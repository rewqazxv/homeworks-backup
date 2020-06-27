# 创建数据库
CREATE DATABASE resort;
use resort;

# 创建对应的用户，并赋予数据库的权限
GRANT ALL PRIVILEGES ON resort.* TO 'resort'@'localhost' IDENTIFIED BY '123' WITH GRANT OPTION;
FLUSH PRIVILEGES;

# 房间类型表
CREATE table room
(
    roomnum  char(16) PRIMARY KEY,
    roomtype char(16) not NULL,
    price    double   not NULL,
    status   char(16) not NULL,
    spaprice double   not NULL,
    username char(64) default null
);

# 用户表
CREATE table user
(
    uid    int PRIMARY KEY AUTO_INCREMENT,
    tel    char(32) not NULL UNIQUE,
    name   char(64) not NULL,
    idcard char(64) not NULL
);

# 密码单独保存
CREATE table password
(
    uid      int       not null,
    password char(255) not NULL,
    FOREIGN key (uid) REFERENCES user (uid),
    isadmin  bool      not NULL default 0
);

# 房间订单表
CREATE table roomorder
(
    roomorderid int PRIMARY KEY AUTO_INCREMENT,
    roomnum     char(16) not NULL,
    FOREIGN key (roomnum) REFERENCES room (roomnum),
    intime      datetime not NULL DEFAULT CURRENT_TIMESTAMP,
    outtime     datetime,
    spa         bool     not NULL,
    mainuid     int      not NULL,
    FOREIGN key (mainuid) REFERENCES user (uid),
    totalprice  double,
    comment     text
);

# 餐饮类型表
CREATE table dish
(
    dishtype char(32) PRIMARY KEY,
    price    double not NULL
);

# 餐饮订单表
CREATE table dishorder
(
    dishorderid   int PRIMARY KEY AUTO_INCREMENT,
    dishtype      char(32) not NULL,
    FOREIGN key (dishtype) REFERENCES dish (dishtype),
    dishorderdate datetime not NULL DEFAULT CURRENT_TIMESTAMP,
    roomorderid   int      not NULL,
    FOREIGN key (roomorderid) REFERENCES roomorder (roomorderid),
    done bool default false
);