<?php
//DebugBreak(); 

$encrypted = $_POST['xml_data'];
if (empty($encrypted)) {
    exit;
}
$decoded = base64_decode($encrypted);
//Dump encrypted data:   
//file_put_contents('encrypted.bin', $decoded, FILE_BINARY); 

//Init session
session_start();

//Init RSA
require_once('RSA.class.php');  
$rsa = new RSA;

$decrypted = $rsa->Decrypt($decoded);   

//Dump decrypted data & signature:
//file_put_contents('message.txt', $decrypted['message'], FILE_BINARY);
//file_put_contents('signature.bin', $decrypted['signature'], FILE_BINARY);      

$dom = new DOMDocument();                 
$dom->loadXML($decrypted['message']); 
//TO DO: Add xml check and error handling
 
$tagRoot = $dom->documentElement;
$reqAction = $tagRoot->getAttribute('action');

if (!isset($_SESSION['ClientSignKey']) && $reqAction=='login') {  
    //Load signature key from request
    $tags = $tagRoot->getElementsByTagName('SignKey');
    $tag = $tags->item(0);
    $reqSignKey = $tag->nodeValue;    
    //Dump key file:
    //file_put_contents('client.sign.bin', base64_decode($reqSignKey), FILE_BINARY);    
    
    $rsa->SetClientSignKey($reqSignKey);  
}

$verifyRes = $rsa->Verify($decrypted);
if ($verifyRes == 1) {
    //Signature OK
}
else if ($verifyRes==0){
    exit('Invalid signature');
}
else {
    exit('Signature verification error :'.openssl_error_string());     
}

//Authorization code here
// ...

//Start building response
$resStatus = 0;
$response = array();

if ($reqAction=='login') {
    //Generate server signature key
    $resSignKey = $rsa->GenerateServerSignKey();   
    $response['SignKey'] = $resSignKey;   

    //Fill response
    $response['Video-Category 1'] = 'Test';  
}   

$message = $resStatus;
foreach($response as $name=>$value) {
    $message .= "\n{$name}: {$value}";
}

$pack = $rsa->Sign($message);
$output = base64_encode($rsa->Encrypt($pack));

print($output);
?>
