openssl req -x509 -nodes -days 365 -newkey rsa:1024 -keyout /etc/ssl/private/ftps-selfsigned.key -out /etc/ssl/certs/ftps-selfsigned.crt << EOF
KO
Seoul
Dongjak
Heukseok
42Seoul
junhpark	
feldblume5263@gmail.com
EOF
vsftpd /etc/vsftpd/vsftpd.conf
