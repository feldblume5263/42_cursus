clear
echo "\033[33m";echo "------------------- junhpark -------------------";echo "\033[0m"
echo "\033[33m";echo "------------------ ft_services -----------------";echo "\033[0m"
sleep 2
clear
echo "\033[33m";echo "---------------- services.sh 실행---------------";echo "\033[0m"
echo "\npress any key\n"
read
clear

#########################################################################################

echo "\033[33m";echo "---------- Minikube를 VirtualBox로 시작 --------";echo "\033[0m"
minikube start --driver=virtualbox
echo "\033[33m";echo "minikube 환경변수 세팅";echo "\033[0m"
eval $(minikube docker-env)
# 이 작업을 해주지 않으면, mySQL에서 secret "account"가 없다는 오류를 출력함.
kubectl create secret generic host-ip --from-literal=HOST_IP="$(ipconfig getifaddr en0)"
kubectl create secret generic account --from-literal=USER="junhpark" --from-literal=PASSWORD="1234"
echo "\npress any key\n"
read
clear

echo "\033[33m";echo "쿠버네티스 내의 도커 이미지";echo "\033[0m"
docker images
echo "\npress any key\n"
echo "\033[33m";echo "쿠버네티스 내의 환경변수";echo "\033[0m"
export | grep "DOCKER"
echo "\npress any key\n"
read
clear

#########################################################################################

echo "\033[33m";echo "----------- Metallb(로드밸런서) 설치 -----------";echo "\033[0m"
minikube addons enable metallb
# kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"
# export ADDRESSES=`ipconfig getifaddr en0`-`ipconfig getifaddr en0`
echo "\033[33m";echo "----- 안정성을  위해 Metallb ip 범위 할당 ------";echo "\033[0m"
export ADDRESSES="- $(minikube ip)-$(minikube ip)"
export | grep "ADDRESSES="
echo "\033[33m";echo "할당 완료...";echo "\033[0m"
echo "\033[33m";echo "----------- 쿠버네티스에 Metallb 적용 ----------";echo "\033[0m"
sed -i "" "s/ADDRESSES/$ADDRESSES/" srcs/metallb/metallb-configmap.yaml
kubectl apply -f srcs/metallb/metallb-configmap.yaml > /dev/null
echo "쿠버네티스에 적용 완료"
sed -i "" "s/$ADDRESSES/ADDRESSES/" srcs/metallb/metallb-configmap.yaml
echo "\npress any key\n"
read
clear

#########################################################################################

echo "\033[33m";echo "------------------ mySQL 적용 ------------------";echo "\033[0m"

echo "\033[33m";echo "mySQL 이미지 빌드";echo "\033[0m"
echo "mysql, mysql-client 설치"
echo "mysql --user=root를 통해 서버 시작 전에 테이블 생성"
docker build -t mysql ./srcs/mysql/ > /dev/null

echo "\033[33m";echo "---------------- mySQL 쿠버네티스 적용 --------------";echo "\033[0m"
echo "\033[33m";echo "<Deployment>";echo "\033[0m"
echo "mySQL 레플리카셋 설정"
echo "\033[33m";echo "<Service>";echo "\033[0m"
echo "port 3306"
kubectl apply -f ./srcs/mysql/mysql.yaml > /dev/null
echo "\033[33m";echo "<PV>";echo "\033[0m"
echo "mysql-pv  500Mi"
echo "\033[33m";echo "<PVC>";echo "\033[0m"
echo "mysql-pvc  500Mi"
kubectl apply -f ./srcs/mysql/mysql-pvc.yaml > /dev/null
echo "\npress any key\n"
read
clear

#########################################################################################

echo "\033[33m";echo "---------------- phpMyAdmin 적용 ---------------";echo "\033[0m"

echo "\033[33m";echo "phpMyAdmin 이미지 빌드";echo "\033[0m"
echo "phpMyAdmin 설치"
echo "config.inc.php파일 수정"
sleep 2
echo "\033[33m";echo "<default.conf>";echo "\033[0m"
echo "default configiguration..."
echo "\033[33m";echo "<wait_process>";echo "\033[0m"
echo "shell program  not to exit process..."
docker build -t phpmyadmin ./srcs/phpmyadmin/ > /dev/null
sleep 1

echo "\033[33m";echo "----------- phpMyAdmin 쿠버네티스 적용  -------------";echo "\033[0m"
echo "\033[33m";echo "<Deployment>";echo "\033[0m"
echo "phpmyadmin Replicaset 설정..."
echo "\033[33m";echo "<Service>";echo "\033[0m"
echo "port 5000"
echo "phpmyadmin의 ip를 minikube ip 하나로 고정..."
kubectl apply -f ./srcs/phpmyadmin/phpmyadmin.yaml > /dev/null
echo "\npress any key\n"
read
clear

#########################################################################################

echo "\033[33m";echo "--------------- WordPress 적용 -----------------";echo "\033[0m"

echo "\033[33m";echo "WordPress 이미지 빌드";echo "\033[0m"
sleep 2
echo "\033[33m";echo "<default.conf>";echo "\033[0m"
echo "default configiguration..."
echo "\033[33m";echo "<wp-config.php>";echo "\033[0m"
echo "Base Configuration..."
echo "Wordpress Key Generate..."
echo "Database Table prefix..."
docker build -t wordpress ./srcs/wordpress/ > /dev/null
sleep 1

echo "\033[33m";echo "------------ WordPress 쿠버네티스 적용  -------------";echo "\033[0m"

echo "\033[33m";echo "<Service>";echo "\033[0m"
echo "접근 가능한 클러스터 ip가 minikube ip 하나임으로 ip 하나로 고정"
echo "포트 5050 할당"
echo "\033[33m";echo "<Deployment>";echo "\033[0m"
echo "Wordpress Replicaset 설정"
echo "Wordpress 이미지 사용"
kubectl apply -f ./srcs/wordpress/wordpress.yaml > /dev/null
echo "\npress any key\n"
read
clear

#########################################################################################

echo "\033[33m";echo "---------------- Nginx 적용  -------------------";echo "\033[0m"

echo "\033[33m";echo "Nginx 이미지 빌드";echo "\033[0m"
echo "ssh key 설정"
echo "https 설정"
echo "www 그룹 추가"
docker build -t nginx ./srcs/nginx/ > /dev/null

echo "\033[33m";echo "------------- Nginx 쿠버네티스 적용 -----------------";echo "\033[0m"

echo "\033[33m";echo "<Deployment>";echo "\033[0m"
echo "Nginx Replicaset 설정"
echo "\033[33m";echo "<Service>";echo "\033[0m"
echo "80, 443, 22 포트 할당"
echo "allow-shared-ip: minikube ip 하나로 고정"
kubectl apply -f ./srcs/nginx/nginx-service.yaml > /dev/null
kubectl apply -f ./srcs/nginx/nginx-deployment.yaml > /dev/null
echo "\npress any key\n"
read
clear

#########################################################################################

echo "\033[33m";echo "----------------- ftps 적용  -------------------";echo "\033[0m"

echo "vsftpd 설치"
echo "vsftpd ssl 설정"
echo "fpts user ID와 psswd 설정"
export _EXTERNAL_IP="$(minikube ip)"
sed -i "" "s/_EXTERNAL_IP/$_EXTERNAL_IP/" srcs/ftps/vsftpd.conf
docker build -t ftps ./srcs/ftps/ > /dev/null

echo "\033[33m";echo "-------------- ftps 쿠버네티스 적용 -----------------";echo "\033[0m"

echo "\033[33m";echo "<Deployment>";echo "\033[0m"
echo "ftps Replicaset 설정"
echo "\033[33m";echo "<Service>";echo "\033[0m"
echo "포트 21(ftps-command), 20000(pasv), 20001(pasv), 20002(pasv), 20003(pasv) 할당"
kubectl apply -f ./srcs/ftps/ftps.yaml > /dev/null
sed -i "" "s/$_EXTERNAL_IP/_EXTERNAL_IP/" srcs/ftps/vsftpd.conf
echo "\npress any key\n"
read
clear

#########################################################################################

echo "\033[33m";echo "--------------- influxDB 적용  -----------------";echo "\033[0m"

echo "influxdb 설치"
echo "influxdb config 파일 컨테이너 내부로 복사"
docker build -t influxdb ./srcs/influxdb/ > /dev/null

echo "\033[33m";echo "------------ influxDB 쿠버네티스 적용 ---------------";echo "\033[0m"

echo "\033[33m";echo "<Deployment>";echo "\033[0m"
echo "influxDB Replicaset 설정"
echo "secretRef 참조"
echo "pv volume 요청"
echo "\033[33m";echo "<Service>";echo "\033[0m"
echo "8086포트 할당"
kubectl apply -f ./srcs/influxdb/influxdb.yaml > /dev/null
echo "\033[33m";echo "<PV>";echo "\033[0m"
echo "influxDB-pv  500Mi"
echo "\033[33m";echo "<PVC>";echo "\033[0m"
echo "influxDB-pvc  500Mi"
kubectl apply -f ./srcs/influxdb/influxdb-pv.yaml > /dev/null
echo "\033[33m";echo "<Secret>";echo "\033[0m"
echo "사용자 정의 데이터 설정"
echo "influxdb.conf 데이터 가져온다."
kubectl apply -f ./srcs/influxdb/influxdb-secret.yaml > /dev/null
echo "\npress any key\n"
read
clear

#########################################################################################

echo "\033[33m";echo "--------------- telegraf 적용  -----------------";echo "\033[0m"

echo "telegraf 설치"
echo "telegraf.conf 복사"
docker build -t telegraf ./srcs/telegraf/ > /dev/null

echo "\033[33m";echo "------------ telegraf 쿠버네티스 적용 ---------------";echo "\033[0m"

echo "\033[33m";echo "<Deployment>";echo "\033[0m"
echo "telegraf 레플리카셋 설정"
kubectl apply -f ./srcs/telegraf/telegraf.yaml > /dev/null
echo "\npress any key\n"
read
clear

#########################################################################################

echo "\033[33m";echo "---------------- Grafana 적용  -----------------";echo "\033[0m"

echo "Grafana 설치"
echo " http://dl-2.alpinelinux.org/alpine/edge/community/"
docker build -t grafana ./srcs/grafana/ > /dev/null

echo "\033[33m";echo "------------- Grafana 쿠버네티스 적용 ---------------";echo "\033[0m"

echo "\033[33m";echo "<Deployment>";echo "\033[0m"
echo "Grafana Replicaset 설정"
echo "\033[33m";echo "<Service>";echo "\033[0m"
echo "port 3000 할당"
kubectl apply -f ./srcs/grafana/grafana.yaml > /dev/null
echo "\033[33m";echo "<Configmap>";echo "\033[0m"
echo "influxDB에 Dashboard 파일 참조"
kubectl apply -f ./srcs/grafana/grafana-configmap.yaml > /dev/null
echo "\npress any key\n"
read
clear

#########################################################################################

minikube dashboard
