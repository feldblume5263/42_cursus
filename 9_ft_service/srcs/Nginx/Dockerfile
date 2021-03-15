FROM	alpine:3.12
EXPOSE	80 443 22

RUN		apk update
RUN 	apk add --no-cache nginx \
				openssl \
				openssh
RUN		mkdir /run/nginx
CMD		nginx -g "daemon off;"
