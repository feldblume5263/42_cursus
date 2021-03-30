FROM		alpine:3.12
EXPOSE		3000

## 미니큐브에서 도커빌드가 안되는 것들

RUN apk update && apk --update --no-cache add  grafana --repository http://dl-2.alpinelinux.org/alpine/edge/community/

COPY		dashboards /usr/share/grafana/public/dashboards
ENTRYPOINT	[ "grafana-server", "--homepath=/usr/share/grafana"]

