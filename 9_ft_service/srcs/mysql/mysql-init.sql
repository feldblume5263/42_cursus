CREATE DATABASE IF NOT EXISTS wordpress;
FLUSH PRIVILEGES;
GRANT ALL PRIVILEGES ON *.* TO 'junhpark'@'%' IDENTIFIED BY '1234' WITH GRANT OPTION;
FLUSH PRIVILEGES;