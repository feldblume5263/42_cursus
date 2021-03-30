FROM	alpine:3.12
EXPOSE	80 443 22

RUN		apk update
RUN 	apk add --no-cache nginx openssl openssh

RUN sed 's/#PermitRootLogin prohibit-password/PermitRootLogin yes/' -i /etc/ssh/sshd_config
RUN echo 'root:1' | chpasswd
RUN ssh-keygen -f /etc/ssh/ssh_host_rsa_key -N '' -t rsa
RUN ssh-keygen -f /etc/ssh/ssh_host_dsa_key -N '' -t dsa
RUN mkdir -p /var/run/sshd


RUN	mkdir -p /run/nginx

# ?? 왜??
RUN adduser -D -g 'www' www
RUN mkdir /www
RUN chown -R www:www /var/lib/nginx
RUN chown -R www:www /www

COPY	./default.conf /etc/nginx/conf.d/default.conf
COPY	index.html /www/index.html

COPY	prevent_exit.sh /prevent_exit.sh
COPY	ssl-setting.sh /ssl-setting.sh

CMD		/ssl-setting.sh; /prevent_exit.sh

