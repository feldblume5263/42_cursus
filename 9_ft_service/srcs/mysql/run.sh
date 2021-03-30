mysql_install_db --user=root
# bootstrap옵션을 사용해 주는 이유는 mysql 서버가 시작되기 전에 먼저 DB 테이블이 만들어져야 하기 때문. 테이블이 만들어져 있지 않은 상황에서 wordpress.sql 데이터가 들어 갈 수 없다. 따라서 wordpress.sql을 해주기 전에 sql 테이터가 입력될 환경을 조성해 주는 것.
# 그리고 mysqld --user=root < init 이 아니라 --bootstrap 옵션으로 먼저 테이블을 생성하고 mysqld --user=root를 하는 이유는 mysqld --user=root는 "서버"를 시작하는 명령이기 때문이다. 서버를 시작하고 나서는 데이터를 넣기 힘들기 때문에 서버를 시작하기 전에 "테이블"을 생성하고 만든 테이블을 갖는 서버를 시작하는 것.
# --bootstrap 옵션을 붙여주는 이유는 결국 서버를 "진짜"로 시작하기 전에 테이블을 만들기 위함
mysqld --user=root --bootstrap < /tmp/mysql-init.sql
# 서버 시작. 서버가 돌아가는 와중에 이제 만들어진 wordpress 테이블에 wordpress.sql 데이터가 들어온다. 이 작업은 wordpress.sql에서 해준다.
mysqld --user=root  # mysql-init.sql에서 만든 아이디가 phpmyadmin으로 접근하는 아이디가 됨
# 포그라운드로 돌아감

/bin/sh # mysqld에 병목현상에 의해서 실행되기만을 기다리는 프로그램
# 혹시나 docker attach 헀을 때, mysqld에서 대기하고 있는 상태라면, ^C, ^\해도 컨테이너가 꺼지지 않도록하기위해서 만들어줬어요
