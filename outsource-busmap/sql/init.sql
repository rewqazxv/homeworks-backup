create database busmap;
go
use busmap;


create table route(
	id int primary key IDENTITY(1,1),
	name char(32) not null unique,
	first char(32),
	last char(32),
	price int
);


create table station(
	id int primary key IDENTITY(1,1),
	name char(32) not null unique
);


create table via(
	rid int FOREIGN KEY REFERENCES route(id),
	sid int FOREIGN KEY REFERENCES station(id),
	num int not null
);


go
create view map as
	select rid as route_id, route.name as route_name, num, sid as station_id, station.name as station_name
	from route, station, via
	where route.id=via.rid and station.id=via.sid;


go
create trigger delete_useless on via for delete as
	declare @data CURSOR;
	declare @id int;

	-- iterate route
	set @data = CURSOR FOR select DISTINCT rid from deleted;
	OPEN @data;
	FETCH NEXT FROM @data INTO @id;
	WHILE @@FETCH_STATUS = 0
	BEGIN
		if not exists (select * from via where rid = @id)
		begin
			delete from route where id=@id;
		end
		FETCH NEXT FROM @data INTO @id;
	end
	close @data;
	DEALLOCATE @data;

	-- iterate station
	set @data = CURSOR FOR select DISTINCT sid from deleted;
	OPEN @data;
	FETCH NEXT FROM @data INTO @id;
	WHILE @@FETCH_STATUS = 0
	BEGIN
		if not exists (select * from via where sid = @id)
		begin
			delete from station where id=@id;
		end
		FETCH NEXT FROM @data INTO @id;
	end
	close @data;
	DEALLOCATE @data;


go
CREATE PROCEDURE addstation
    @name char(32),
	@rid int,
	@num int
AS
	declare @sid int;
	set @sid = (select id from station where name=@name);
	if @sid is null
	begin
		insert into station(name) values (@name);
		set @sid = (select id from station where name=@name);
	end
	update via set num=num+1 where rid=@rid and num>=@num;
	insert into via(rid,sid,num) values (@rid,@sid,@num);


go
CREATE PROCEDURE delstation
	@sid int
as
	declare @data cursor;
	declare @id int;
	declare @num int;
	set @data = cursor for select rid,num from via where sid=@sid;
	open @data;
	FETCH NEXT FROM @data INTO @id,@num;
	WHILE @@FETCH_STATUS = 0
	BEGIN
		update via set num=num-1 where rid=@id and num>@num;
		delete from via where rid=@id and sid=@sid;
		FETCH NEXT FROM @data INTO @id,@num;
	end
	close @data;
	DEALLOCATE @data;
	delete from station where id=@sid