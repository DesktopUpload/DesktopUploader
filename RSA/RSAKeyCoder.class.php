<?php

abstract class RSAKeyCoder
{
      public $Modulus = '';
      public $PublicExponent = 0;
      
      function __construct($Der='')
      {
          if (!empty($Der)) {
              $this->DecodeDer($Der);
          }
      }
      
      abstract function DecodeDer($Der);
      abstract function EncodeDer();
      
      function getByteLength()
      {
          return strlen($this->Modulus);
      }
}

class RSAPublicKeyCoder extends RSAKeyCoder
{   
    const HEADER_BYTES = "\x30\x0d\x06\x09\x2a\x86\x48\x86\xf7\x0d\x01\x01\x01\x05\x00";   
    
    function DecodeDer($Der)
    {
        //Decode root sequence
        $body = new ASNValue;
        $body->Decode($Der);
        $bodyItems = $body->GetSequence(); 

        //Seek to bit string with keys
        $bitStringValue = $bodyItems[1]->Value;
        $bitStringValue = substr($bitStringValue, 1); //Skip unused bits 

        //Decode key sequence
        $keySequence = new ASNValue;
        $keySequence->Decode($bitStringValue);
        $keySequenceItems = $keySequence->GetSequence();
        //Read modulus
        $this->Modulus = $keySequenceItems[0]->GetIntBuffer();
        //Read exponent
        $this->PublicExponent = $keySequenceItems[1]->GetInt();   
    }
    
    function EncodeDer()
    {
        //Encode key sequence
        $modulus = new ASNValue(ASNValue::TAG_INTEGER);
        $modulus->SetIntBuffer($this->Modulus);
        $publicExponent = new ASNValue(ASNValue::TAG_INTEGER);
        $publicExponent->SetInt($this->PublicExponent);
        
        $keySequenceItems = array($modulus, $publicExponent);  
        $keySequence = new ASNValue(ASNValue::TAG_SEQUENCE);
        $keySequence->SetSequence($keySequenceItems);
        
        //Bit string  
        $bitStringValue = $keySequence->Encode();
        $bitStringValue = chr(0x00) . $bitStringValue; //Unused bits
        $bitString = new ASNValue(ASNValue::TAG_BITSTRING); //bit string
        $bitString->Value = $bitStringValue;

        //Encode body   
        $bodyValue = self::HEADER_BYTES;        
        $bodyValue .= $bitString->Encode();
        
        $body = new ASNValue(ASNValue::TAG_SEQUENCE);   
        $body->Value = $bodyValue;
        $result = $body->Encode();
        
        return $result; 
    }
}

class RSAPrivateKeyCoder extends RSAKeyCoder
{
    public  $Prime1='';
    public  $Prime2='';
    public  $Exponent1='';
    public  $Exponent2='';
    public  $Coefficient='';
    public  $PrivateExponent='';
    
    function DecodeDer($Der)
    {              
        //Decode root sequence
        $body = new ASNValue;
        $body->Decode($Der);
        $bodyItems = $body->GetSequence();
        
        //Read modulus
        $this->Modulus = $bodyItems[1]->GetIntBuffer();
        //Read public exponent
        $this->PublicExponent = $bodyItems[2]->GetInt();     
        //Read private exponent
        $this->PrivateExponent = $bodyItems[3]->GetIntBuffer();    
        //Read prime1
        $this->Prime1 = $bodyItems[4]->GetIntBuffer();     
        //Read prime2
        $this->Prime2 = $bodyItems[5]->GetIntBuffer();     
        //Read exponent1
        $this->Exponent1 = $bodyItems[6]->GetIntBuffer();    
        //Read exponent2
        $this->Exponent2 = $bodyItems[7]->GetIntBuffer();    
        //Read coefficient
        $this->Coefficient = $bodyItems[8]->GetIntBuffer();   
    }
    
    function EncodeDer()
    {
        throw new Exception('Method not implemented.');    
    }
}


class ASNValue
{
    const TAG_INTEGER   = 0x02;
    const TAG_BITSTRING = 0x03;
    const TAG_SEQUENCE  = 0x30;
    
    public $Tag;
    public $Value;
    
    function __construct($Tag=0x00, $Value='')
    {
        $this->Tag = $Tag;
        $this->Value = $Value;
    }
    
    function Encode()
    {   
        //Write type
        $result = chr($this->Tag);

        //Write size
        $size = strlen($this->Value);
        if ($size < 127) {
            //Write size as is
            $result .= chr($size);
        }
        else {
            //Prepare length sequence
            $sizeBuf = self::IntToBin($size);

            //Write length sequence
            $firstByte = 0x80 + strlen($sizeBuf);
            $result .= chr($firstByte) . $sizeBuf;
        }

        //Write value
        $result .= $this->Value;
        
        return $result;
    }
    
    function Decode(&$Buffer)
    {   
        //Read type
        $this->Tag = self::ReadByte($Buffer);

        //Read first byte
        $firstByte = self::ReadByte($Buffer);  

        if ($firstByte < 127) {
            $size = $firstByte;
        }
        else if ($firstByte > 127) {
            $sizeLen = $firstByte - 0x80;
            //Read length sequence
            $size = self::BinToInt(self::ReadBytes($Buffer, $sizeLen));
        }
        else {
            throw new Exception("Invalid ASN length value");
        }

        $this->Value = self::ReadBytes($Buffer, $size);
    }
    
    protected static function ReadBytes(&$Buffer, $Length)
    {
        $result = substr($Buffer, 0, $Length);
        $Buffer = substr($Buffer, $Length);
        
        return $result;
    }
    
    protected static function ReadByte(&$Buffer)
    {      
        return ord(self::ReadBytes($Buffer, 1));
    }
    
    protected static function BinToInt($Bin)
    {    
        $len = strlen($Bin);
        $result = 0;
        for ($i=0; $i<$len; $i++) {
            $curByte = self::ReadByte($Bin);
            $result += $curByte << (($len-$i-1)*8);
        }
        
        return $result;
    }
    
    protected static function IntToBin($Int)
    {
        $result = '';
        do {
            $curByte = $Int % 256;
            $result .= chr($curByte);

            $Int = ($Int - $curByte) / 256;
        } while ($Int > 0);

        $result = strrev($result);
        
        return $result;
    }
    
    function SetIntBuffer($Value)
    {
        if (strlen($Value) > 1) {
            $firstByte = ord($Value{0});
            if ($firstByte & 0x80) { //first bit set
                $Value = chr(0x00) . $Value;
            }
        }
        
        $this->Value = $Value;
    }
    
    function GetIntBuffer()    
    {        
        $result = $this->Value;
        if (ord($result{0}) == 0x00) {
            $result = substr($result, 1);
        }
        
        return $result;
    }
    
    function SetInt($Value)
    {
        $Value = self::IntToBin($Value);
        
        $this->SetIntBuffer($Value);
    }   
    
    function GetInt()
    {
        $result = $this->GetIntBuffer();
        $result = self::BinToInt($result);
        
        return $result;
    }
    
    function SetSequence($Values)
    {
        $result = '';
        foreach ($Values as $item) {
            $result .= $item->Encode();            
        }   
        
        $this->Value = $result;
    }   
    
    function GetSequence()
    {
        $result = array();
        $seq = $this->Value;
        while (strlen($seq)) {
            $val = new ASNValue();
            $val->Decode($seq);
            $result[] = $val;
        }  
        
        return $result;
    }    
}
?>
