CREATE TABLE IF NOT EXISTS `voter_result` (
  `voter_id` int(11) NOT NULL,
  `candidate_id` int(11) NOT NULL,
  PRIMARY KEY (`voter_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8;

