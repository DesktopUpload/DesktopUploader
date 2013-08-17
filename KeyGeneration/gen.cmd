SET keyLength=2048

del /Q /S client.pem
del /Q /S server.pem
del /Q /S client\*.*
del /Q /S server\*.*
mkdir client
mkdir server


openssl genrsa -out client.pem %keyLength%
openssl genrsa -out server.pem %keyLength%

openssl rsa -in client.pem -out client\client.private.der -outform DER
openssl rsa -pubout -in client.pem -out server\client.public.der -outform DER
openssl rsa -in server.pem -out server\server.private.der -outform DER
openssl rsa -pubout -in server.pem -out client\server.public.der -outform DER
