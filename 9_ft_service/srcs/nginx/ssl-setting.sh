openssl req -x509 -nodes -days 365 -newkey rsa:1024 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt << EOF
KO
Seoul
Dongjak
Heukseok
42Seoul
junhpark	
feldblume5263@gmail.com
EOF
openssl dhparam -out /etc/ssl/certs/dhparam.pem 1024
