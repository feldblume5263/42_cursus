FROM		alpine
EXPOSE		80 443 22
RUN			apk add nginx openssl openssh
COPY		nginx_start.sh /tmp
RUN			chmod +x /tmp/nginx_start.sh
ENTRYPOINT	[ "/bin/sh", "/tmp/nginx_start.sh" ]
