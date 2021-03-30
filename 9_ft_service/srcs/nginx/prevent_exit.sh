#!/bin/sh
echo “Prevent exit container”
/usr/sbin/sshd # 절대경로로 실행시켜줘야 실행되야한다. 본인의 위치를 알고싶다나 뭐라나
nginx -g 'daemon off;' # sh에서 대기 상태로 존재
# /bin/sh # ^\ 로 중지 시켜도 container shell에 존재하도록 하기위해서!, 다만 subject의 persistance를 충족시키기위해서는 주석처리를 해야한다.

# nginx #nginx 시작
# nginx -s quit #nginx 종료
