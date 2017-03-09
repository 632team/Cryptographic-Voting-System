CREATE TABLE candidate_information (
	 candidate_id int AUTO_INCREMENT,
	 candidate_name varchar(20) NOT NULL,
	 candidate_age int NOT NULL,
	 candidate_sex ENUM('ÄÐ', 'Å®'),
	 candidate_ic varchar(20) NOT NULL UNIQUE,
	 candidate_record varchar(500) NOT NULL,
	 CONSTRAINT pk_id PRIMARY KEY(candidate_id)
) ENGINE=InnoDB;