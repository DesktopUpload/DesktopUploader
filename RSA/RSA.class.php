<?php
error_reporting(E_ALL);
ini_set('display_errors', '1');
 
define('RSA_SIGNATUREKEY_LENGTH', 1024);      
define('USE_OPENSSL_PKEY_GETDETAILS', PHP_VERSION >= '5.2');

if (!USE_OPENSSL_PKEY_GETDETAILS) {
    require_once('RSAKeyCoder.class.php');
}     

class RSA
{
    protected $ServerKey;
    protected $ClientKey;
    protected $ServerSignKey;    
    protected $ClientSignKey;  
    
    public function __construct()
    {
        $this->ServerKey = $this->LoadKeyFromFile(dirname(__FILE__).'/server.private.der', true);  
        $this->ClientKey = $this->LoadKeyFromFile(dirname(__FILE__).'/client.public.der', false);

        
        $this->LoadSessionKeys();   
    }
    
    function Encrypt($Pack)
    // Encrypts data package   
    {
        $data = $this->JoinMessage($Pack['message'], $Pack['signature']);
        $chunks = str_split($data, $this->ClientKey->ByteLength-11);  
        
        $encrypted = '';
        foreach($chunks as $chunk) {   
            if (!openssl_public_encrypt($chunk, $res, $this->ClientKey->KeyHandle)) {
                exit('Encryption failed :'.openssl_error_string()); 
            }
            $encrypted .= $res;    
        }
        
        return $encrypted;      
    }
    
    function Sign($Data)
    //Signs data with server signature key
    {
        if (!openssl_sign($Data, $signature, $this->ServerSignKey->KeyHandle)) {
            exit('Signing failed :'.openssl_error_string());          
        } 
        return array(
            'message' => $Data,
            'signature' => $signature);  
    }
    
    function Decrypt($Data)
    // Decrypts chunked encrypted data
    {
        $chunks = str_split($Data, $this->ServerKey->ByteLength);

        $decrypted = '';
        foreach($chunks as $chunk) {   
            if (!openssl_private_decrypt($chunk, $out, $this->ServerKey->KeyHandle)) {
                exit('Decryption failed :'.openssl_error_string());  
            }
            $decrypted .= $out;    
        }
        
        return $this->SplitMessage($decrypted);
    }
    
    function Verify($Pack)
    // Verifies associative array returned by Decrypt method with digital signature
    {
        $key = $this->ClientSignKey;

        $signature = $Pack['signature'];
        if (strlen($signature)!=$key->ByteLength) {
            exit('Invalid signature length');
        }

        return openssl_verify($Pack['message'], $signature, $key->KeyHandle);
    }
    
    protected function SplitMessage($Pack)
    //Splits message body and signature into associative array 
    {
        $parts = explode(chr(0x00), $Pack, 2);
        if ($parts===false || count($parts) != 2 || empty($parts[0]) || empty($parts[1])) {
            exit('Invalid message');
        }
        
        return array(
            'message' => $parts[0],
            'signature' => $parts[1]);    
    }
    
    protected function JoinMessage($Message, $Signature)
    //Joins message body and signature into zero byte delimited sequence 
    {
        return $Message . chr(0x00) . $Signature;    
    }
    
    protected function LoadSessionKeys()
    {
    //Restore signature keys from session
        if (isset($_SESSION['ClientSignKey'])) {
            $this->ClientSignKey = $this->LoadKeyFromString($_SESSION['ClientSignKey'], false);    
        }  
        if (isset($_SESSION['ServerSignKey'])) {
            $this->ServerSignKey = $this->LoadKeyFromString($_SESSION['ServerSignKey'], true);      
        } 
    }
    
    function GenerateServerSignKey()
    //Generates new server signature key and exports public key DER  
    {
        $this->ServerSignKey = new RSAKey();
        $this->ServerSignKey->Generate(RSA_SIGNATUREKEY_LENGTH, $private, $public); 
        
        $_SESSION['ServerSignKey'] = $private;  
        
        return $public;
    }
    
    function SetClientSignKey($Data)
    //Loads client signature key 
    {
        $this->ClientSignKey = $this->LoadKeyFromString($Data, false);
        $_SESSION['ClientSignKey'] = $Data;
    }
    
    protected function LoadKeyFromFile($FileName, $Private=false)
    //Loads key from DER file
    {
        $der = file_get_contents($FileName);
        $result = new RSAKey();
        $result->Import($der, $Private);
        
        return $result;
    }
    
    protected function LoadKeyFromString($Data, $Private=false)
    //Loads key from base64 encoded DER string
    {
        $result = new RSAKey();
        $result->Import(base64_decode($Data), $Private);
        
        return $result;
    }
}


class RSAKey
{
    public $KeyHandle;
    public $Private = false;
    public $ByteLength;
    
    public function Generate($KeyLength, &$Private, &$Public) 
    // Generates new keypair
    {
        $configArgs = array(
            'config' => dirname(__FILE__).DIRECTORY_SEPARATOR.'openssl.cnf',
            //'config' => '/usr/local/psa/admin/conf/openssl.cnf',
            'private_key_bits' => $KeyLength
        );
        $handle = openssl_pkey_new($configArgs);
        if (!$handle) {
            exit ("Key generation failed: ".openssl_error_string()); 
        }
        
        $this->Private = true;    
        $this->Init($handle, $Private); 
        $this->ByteLength = $KeyLength/8;
        
        // Get private key
        if (!openssl_pkey_export($handle, $pem, NULL, $configArgs)) {
            exit ("Key export failed: ".openssl_error_string());      
        }
        $Private = RSAKey::PemToDer($pem);  
        $_SESSION['ServerSignKey'] = $Private;
        
        // Get public key
        if (USE_OPENSSL_PKEY_GETDETAILS) {
            $info = openssl_pkey_get_details($handle);
            $pem = $info["key"];  ;
            $Public = RSAKey::PemToDer($pem);    
        }
        else {
            $privateCoder = new RSAPrivateKeyCoder(base64_decode($Private));
            $publicCoder = new RSAPublicKeyCoder;
            $publicCoder->Modulus = $privateCoder->Modulus;
            $publicCoder->PublicExponent = $privateCoder->PublicExponent;
            $Public = base64_encode($publicCoder->EncodeDer());
        }
    }
    
    public function Import($Der, $Private=false)
    // Inports key PEM data
    {
        $pem = self::DerToPem($Der, $Private, true);
        
        $handle = $Private? 
            openssl_pkey_get_private($pem) : 
            openssl_pkey_get_public($pem);
        if (!$handle) {
            exit ("Key load failed: ".openssl_error_string());    
        }
            
        $this->Private = $Private;
        $this->Init($handle, $Private);
        
        //Key length
        if (USE_OPENSSL_PKEY_GETDETAILS) {
            $info = openssl_pkey_get_details($handle);
            $this->ByteLength = $info['bits']/8;    
        }
        else {
            $info = $Private? new RSAPrivateKeyCoder($Der) : new RSAPublicKeyCoder($Der);
            $this->ByteLength = $info->getByteLength();
        }
    } 
    
    protected function Init($KeyHandle, $Private=false)
    // Initializes key properties
    {
        $this->KeyHandle = $KeyHandle;
        $this->Private = $Private;      
    }
    
    public function __destruct()
    {
        if ($this->KeyHandle) {
            openssl_pkey_free($this->KeyHandle);    
        }
    }
    
    static public function DerToPem($Der, $Private=false, $Base64Encode=true)
    //Converts DER key format to PEM
    {
        if ($Base64Encode) {
            $Der = base64_encode($Der);        
        }
        $lines = str_split($Der, 65);
        $body = implode("\n", $lines);
        
        $title = $Private? 'RSA PRIVATE KEY' : 'PUBLIC KEY';
        
        $result = "-----BEGIN {$title}-----\n";
        $result .= $body . "\n";
        $result .= "-----END {$title}-----\n";
        
        return $result;
    }    
    
    static public function PemToDer($Pem, $Base64Decode=false)
    //Converts PEM key format to DER
    {
        //Split lines
        $lines = explode("\n", trim($Pem));
        //Remove last and first line
        unset($lines[count($lines)-1]);
        unset($lines[0]);  
        //Join lines
        $result = implode('', $lines); 
        
        if ($Base64Decode) {
            $result = base64_decode($result);        
        }
        
        return $result;
    }
}
?>
