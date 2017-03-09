-- phpMyAdmin SQL Dump
-- version 4.0.10deb1
-- http://www.phpmyadmin.net
--
-- 主机: localhost
-- 生成日期: 2017-03-09 15:13:58
-- 服务器版本: 5.5.54-0ubuntu0.14.04.1
-- PHP 版本: 5.5.9-1ubuntu4.21

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- 数据库: `cryptographic_voting_system`
--

-- --------------------------------------------------------

--
-- 表的结构 `candidate_information`
--

CREATE TABLE IF NOT EXISTS `candidate_information` (
  `candidate_id` int(11) NOT NULL AUTO_INCREMENT,
  `candidate_name` varchar(20) NOT NULL,
  `candidate_age` int(11) NOT NULL,
  `candidate_sex` enum('男','女') DEFAULT NULL,
  `candidate_ic` varchar(20) NOT NULL,
  `candidate_record` varchar(500) NOT NULL,
  PRIMARY KEY (`candidate_id`),
  UNIQUE KEY `candidate_ic` (`candidate_ic`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=4 ;

--
-- 转存表中的数据 `candidate_information`
--

INSERT INTO `candidate_information` (`candidate_id`, `candidate_name`, `candidate_age`, `candidate_sex`, `candidate_ic`, `candidate_record`) VALUES
(1, '梁先锋', 20, '男', '352202xxxxxxxxxxxx', '632寝室长，最胖，没有之一，水平一流！'),
(2, '赵欢', 20, '男', '352203xxxxxxxxxxxx', '632荣誉成员，最高，没有之一，别和我比C++！'),
(3, '王辰辰', 21, '男', '352204xxxxxxxxxxxx', '632荣誉成员，最快，没有之一，别和我比做题！');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
