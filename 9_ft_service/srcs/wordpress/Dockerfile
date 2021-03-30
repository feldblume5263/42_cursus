FROM alpine:3.12
EXPOSE 5050

# nginx 설치
RUN apk update > /dev/null 2>&1
RUN apk add nginx > /dev/null 2>&1
RUN mkdir -p /run/nginx

# php패키지 설치
RUN apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session

# wordpress 설치
RUN wget https://wordpress.org/latest.tar.gz && tar -xvf latest.tar.gz > /dev/null 2>&1
RUN rm -rf latest.tar.gz > /dev/null 2>&1
RUN mv wordpress /tmp

COPY default.conf /etc/nginx/conf.d/
COPY wp-config.php /tmp/wordpress/wp-config.php

# Process가 끝나지 않도록 설정
#CMD exec /bin/bash -c "trap : TERM INT; sleep infinity & wait"
COPY wait_process.sh /tmp/
RUN chmod +x /tmp/wait_process.sh
CMD /tmp/wait_process.sh
