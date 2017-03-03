CREATE TABLE voter_information (
	 voter_id int AUTO_INCREMENT,
	 voter_name varchar(20) NOT NULL,
	 voter_age int NOT NULL,
	 voter_sex ENUM('ÄÐ', 'Å®'),
	 voter_ic varchar(20) NOT NULL UNIQUE,
	 voter_password varchar(20) NOT NULL,
	 CONSTRAINT pk_id PRIMARY KEY(voter_id)
) ENGINE=InnoDB;