FROM alpine:3.12

RUN apk add --update --no-cache influxdb

EXPOSE 8086

COPY		influxdb.conf /etc/influxdb/influxdb.conf
ENTRYPOINT ["/usr/sbin/influxd"]
