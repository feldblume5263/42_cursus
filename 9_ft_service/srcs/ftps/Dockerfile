FROM		alpine:3.12
EXPOSE		21 20000-20003
RUN			apk update
RUN			apk add vsftpd openssl


COPY		./ssl-setting.sh /ssl-setting.sh
COPY		./prevent_exit.sh /prevent_exit.sh
COPY		./vsftpd.conf /etc/vsftpd

# fpts의 사용자명과 비밀번호 설정
RUN			echo 'root:1' | chpasswd
CMD			/ssl-setting.sh ; /prevent_exit.sh
