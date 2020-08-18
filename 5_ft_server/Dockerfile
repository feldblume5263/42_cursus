FROM debian:buster
LABEL MAINTAINER = "junhpark<junhpark@student.42seoul.kr>"

# update before start
RUN apt-get update
RUN apt-get -y upgrade

# install nginx
RUN apt-get -y install nginx

# make openssl and give authority
RUN apt-get -y install openssl vim
RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Junhpark/CN=localhost" -keyout etc/ssl/private/localhost.dev.key -out etc/ssl/certs/localhost.dev.crt
RUN chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

# php-fpm 설치
RUN apt-get -y install php-fpm

# mariaDB(mysql) 설치
RUN apt-get -y install mariadb-server php-mysql

# phpMyAdmin 압축해제 후 설치
RUN apt-get install -y wget
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
RUN tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
RUN mv phpMyAdmin-5.0.2-all-languages phpmyadmin
RUN mv phpmyadmin /var/www/html/

# phpMyAdmin 환경설정
RUN cp -rp var/www/html/phpmyadmin/config.sample.inc.php var/www/html/phpmyadmin/config.inc.php

# wordpress 설치 후 환경설정
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvf latest.tar.gz
RUN mv wordpress/ var/www/html/
RUN chown -R www-data:www-data /var/www/html/wordpress
RUN cp var/www/html/wordpress/wp-config-sample.php var/www/html/wordpress/wp-config.php

# 파일 복사
COPY srcs/set_mysql.sh ./
COPY srcs/default ./etc/nginx/sites-available/default
COPY srcs/phpinfo.php ./var/www/html/phpinfo.php
COPY srcs/config.inc.php ./var/www/html/phpmyadmin/config.inc.php
COPY srcs/wp-config.php ./var/www/html/wordpress/wp-config.php

# setup mysql and run service
CMD bash set_mysql.sh

