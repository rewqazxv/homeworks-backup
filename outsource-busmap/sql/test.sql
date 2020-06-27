use busmap;

set IDENTITY_INSERT route ON
insert into route(id,name,first,last,price) values (1,'一号线','6:00','22:00',2);
insert into route(id,name,first,last,price) values (2,'二号线','5:00','23:00',1);
set IDENTITY_INSERT route OFF

exec addstation '东',1,1;
exec addstation '南',1,2;
exec addstation '西',1,3;
exec addstation '北',1,4;
exec addstation '加',2,1;
exec addstation '南',2,2;
exec addstation '减',2,3;