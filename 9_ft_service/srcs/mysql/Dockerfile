FROM alpine:3.12

RUN apk update && apk --update --no-cache add mysql mysql-client

# RUN addgroup mysql mysql
RUN mkdir /run/mysqld
COPY my.cnf /etc/mysql/my.cnf
COPY mysql-init.sql /tmp/
COPY run.sh /run.sh

CMD /run.sh

EXPOSE 3306
