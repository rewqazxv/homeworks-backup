INSERT INTO resort.room (roomnum, roomtype, price, status, spaprice) VALUES ('1101', '双人间', 100, 'empty', 250);
INSERT INTO resort.room (roomnum, roomtype, price, status, spaprice) VALUES ('1102', '双人间', 100, 'empty', 250);
INSERT INTO resort.room (roomnum, roomtype, price, status, spaprice) VALUES ('1201', '大床房', 100, 'empty', 250);
INSERT INTO resort.room (roomnum, roomtype, price, status, spaprice) VALUES ('1202', '大床房', 100, 'empty', 250);
INSERT INTO resort.room (roomnum, roomtype, price, status, spaprice) VALUES ('1301', '三人间', 150, 'empty', 300);
INSERT INTO resort.room (roomnum, roomtype, price, status, spaprice) VALUES ('1302', '豪华总统套间', 1000, 'empty', 2500);

INSERT INTO resort.dish (dishtype, price) VALUES ('椒盐咸鱼', 20);
INSERT INTO resort.dish (dishtype, price) VALUES ('清蒸鲈鱼', 70);
INSERT INTO resort.dish (dishtype, price) VALUES ('盐鱼', 50);
INSERT INTO resort.dish (dishtype, price) VALUES ('鱼头羹', 60);

INSERT INTO resort.user (uid, tel, name, idcard) VALUES (1, '115', '李1', '352123199813215421');
INSERT INTO resort.user (uid, tel, name, idcard) VALUES (2, '15202001435', '张3', '352123199813215421');
INSERT INTO resort.user (uid, tel, name, idcard) VALUES (3, '15202001436', '张4', '352123199813215421');
INSERT INTO resort.user (uid, tel, name, idcard) VALUES (4, '15202001437', '赵5', '352123199813215421');

INSERT INTO resort.password (uid, password, isadmin) VALUES (1, '115', 1);
INSERT INTO resort.password (uid, password) VALUES (2, '115');
INSERT INTO resort.password (uid, password) VALUES (3, '115');
INSERT INTO resort.password (uid, password) VALUES (4, '115');