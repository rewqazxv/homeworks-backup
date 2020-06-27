USE editor_manager;

INSERT INTO `user`(email,password,name,unit,is_reviewer)
VALUES
('a@test.com','123','a','cczu',FALSE),
('b@test.com','123','b','cczu',FALSE),
('c@test.com','123','c','cczu',TRUE),
('d@test.com','123','d','cczu',TRUE),
('e@test.com','123','e','cczu',TRUE),
('f@test.com','123','f','cczu',TRUE);

INSERT INTO `user`(email, password, name, is_admin)
VALUES ('admin@self.com','123','admin',TRUE);

INSERT INTO article(author_id,title,content)
VALUES
(1,'Hello','e1 article'),
(3,'World','e2 article');

CALL search_by_user_name('a');
