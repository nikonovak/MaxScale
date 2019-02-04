RESET MASTER;
CREATE DATABASE test;

CREATE TABLE test.pet (
    ID int NOT NULL AUTO_INCREMENT,
    name varchar(255) NOT NULL,
    time varchar(255),
    PRIMARY KEY (ID)
);

GRANT USAGE ON *.* TO 'niko'@'%' IDENTIFIED BY 'bob';
GRANT ALL ON test.* TO 'niko'@'%';

CREATE USER 'maxuser'@'127.0.0.1' IDENTIFIED BY 'maxpwd';
CREATE USER 'maxuser'@'%' IDENTIFIED BY 'maxpwd';
GRANT ALL ON *.* TO 'maxuser'@'127.0.0.1' WITH GRANT OPTION;
GRANT ALL ON *.* TO 'maxuser'@'%' WITH GRANT OPTION;

SET GLOBAL max_connections=10000;
SET GLOBAL gtid_strict_mode=ON;
