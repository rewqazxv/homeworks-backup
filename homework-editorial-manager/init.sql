DROP USER 'editor_manager'@'%';
FLUSH PRIVILEGES;
DROP DATABASE `editor_manager`;

CREATE DATABASE editor_manager DEFAULT CHARACTER SET utf8;
CREATE USER 'editor_manager'@'%';
ALTER USER 'editor_manager'@'%' IDENTIFIED BY 'test';
GRANT All ON editor_manager.* TO 'editor_manager'@'%';
FLUSH PRIVILEGES;
USE editor_manager;

CREATE TABLE `user`
(
  id          INT PRIMARY KEY AUTO_INCREMENT,
  email       VARCHAR(255) UNIQUE CHECK (email LIKE '%_@__%.__%'),
  password    VARCHAR(255) NOT NULL,
  name        VARCHAR(255) NOT NULL,
  unit        VARCHAR(255),
  is_reviewer BOOLEAN DEFAULT FALSE,
  is_admin    BOOLEAN DEFAULT FALSE
);

CREATE TABLE article
(
  id                    INT PRIMARY KEY AUTO_INCREMENT,
  author_id             INT                    NOT NULL,

  title                 VARCHAR(255),
  category              VARCHAR(255),
  keywords              TEXT,
  submit_date           DATETIME DEFAULT NOW() NOT NULL,
  update_date           DATETIME DEFAULT NOW() NOT NULL,

  paid_review_fee       BOOLEAN  DEFAULT FALSE,
  paid_page_charges     BOOLEAN  DEFAULT FALSE,
  received_remuneration BOOLEAN  DEFAULT FALSE,

  passed                BOOLEAN  DEFAULT FALSE,

  content               LONGTEXT,

  FOREIGN KEY (author_id) REFERENCES user (id)
);

CREATE TABLE comment
(

  id             INT PRIMARY KEY AUTO_INCREMENT PRIMARY KEY,
  article_id     INT,
  reviewer_id    INT,
  review_passed  BOOLEAN           DEFAULT FALSE,
  review_date    DATETIME NOT NULL DEFAULT '1970-01-01',
  review_comment TEXT,
  FOREIGN KEY (reviewer_id) REFERENCES `user` (id),
  FOREIGN KEY (article_id) REFERENCES article (id)
);

DELIMITER //
CREATE TRIGGER update_status
  AFTER UPDATE
  ON comment
  FOR EACH ROW
BEGIN
  IF NOT EXISTS(SELECT review_passed
                FROM comment
                WHERE comment.article_id = NEW.article_id
                  AND comment.review_passed = FALSE) THEN
    UPDATE article
    SET passed= TRUE
    WHERE article.id = NEW.article_id;
  END IF;
END //
DELIMITER ;

DELIMITER //
CREATE TRIGGER add_comments
  AFTER INSERT
  ON article
  For EACH ROW
BEGIN
  DECLARE done INT DEFAULT FALSE;
  DECLARE x INT;
  DECLARE cur1 CURSOR FOR
    SELECT id
    FROM `user`
    WHERE id <> NEW.author_id
      AND is_reviewer = TRUE
    ORDER BY RAND()
    LIMIT 3;
  DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

  OPEN cur1;
  read_loop:
    LOOP
      FETCH cur1 INTO x;
      IF done THEN
        LEAVE read_loop;
      END IF;
      INSERT INTO comment(article_id, reviewer_id) VALUES (NEW.id, x);
    END LOOP;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE search_by_user_name(IN user_name VARCHAR(255))
BEGIN
  SELECT title, category, keywords, passed
  FROM `user`,
       article
  WHERE `user`.id = article.author_id
    AND `user`.name = user_name;
END //
DELIMITER ;
