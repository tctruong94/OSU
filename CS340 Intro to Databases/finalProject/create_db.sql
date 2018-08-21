/************************************************
** Name: Thanhbinh Truong
** Assignment: Final Project
** Class: CS340 Introduction to Database
** Date: March, 14th, 2018
************************************************/

/************************************************
** Program: THE NBA Database
************************************************/

/************************************************
** Just incase someone tries to make a table with a name already in use 
************************************************/
DROP TABLE IF EXISTS `player`;
DROP TABLE IF EXISTS `player_team`;
DROP TABLE IF EXISTS `position`;
DROP TABLE IF EXISTS `player_position`;
DROP TABLE IF EXISTS `player_Conference`;
DROP TABLE IF EXISTS `team`;
DROP TABLE IF EXISTS `team_Conference`;
DROP TABLE IF EXISTS `league_Conference`;


/************************************************
** Name: player table
** Description: table of the players in the league containing their information
************************************************/
CREATE TABLE `player` (
	`player_id` int(11) NOT NULL AUTO_INCREMENT,
        `firstName_Player` varchar(255) NOT NULL,
        `lastName_Player` varchar(255) NOT NULL,
        `age` int(11) NOT NULL,
        `years_In_League` int(11) NOT NULL,
        PRIMARY KEY (`player_id`)
) ENGINE=InnoDB;


/************************************************
** Name: position
** Description: Table of the different positions in the NBA
************************************************/
CREATE TABLE `position` (
        `position_id` int(11) NOT NULL AUTO_INCREMENT,
        `pos_name` varchar(255) NOT NULL,
        PRIMARY KEY (`position_id`),
        UNIQUE KEY (`pos_name`)
) ENGINE=InnoDB;


/************************************************
** Name: team table
** Description: table of the teams in the NBA
************************************************/
CREATE TABLE `team` (
	`team_id` int(11) NOT NULL AUTO_INCREMENT,
        `team_name` varchar(255) NOT NULL,
        `city` varchar(255) NOT NULL,
        `number_of_Ships` int(11),
        PRIMARY KEY (`team_id`),
        UNIQUE KEY (`team_name`)
) ENGINE=InnoDB;


/************************************************
** Name:league_Conference
** Description: Divisons in the NBA
************************************************/
CREATE TABLE `league_Conference` (
	`league_id` int(11) NOT NULL AUTO_INCREMENT,
        `conference_Name` varchar(255) NOT NULL,
        `num_teams` int(11) NOT NULL,
        PRIMARY KEY (`league_id`),
        UNIQUE KEY (`conference_Name`)
) ENGINE=InnoDB;


/************************************************
** Name: player_position
** Description: relationship of which players hold which position
** Relationship: many to many (many players can have many positions)
************************************************/
CREATE TABLE `player_position` (
	`pid` int(11) NOT NULL,
        `pos_id` int(11) NOT NULL,
        PRIMARY KEY (`pid`, `pos_id`),
        FOREIGN KEY (`pid`) REFERENCES `player` (`player_id`)
		ON DELETE CASCADE
                ON UPDATE CASCADE,
	FOREIGN KEY (`pos_id`) REFERENCES `position` (`position_id`)
		ON DELETE CASCADE
                ON UPDATE CASCADE
) ENGINE=InnoDB;


/************************************************
** Name: player_team
** Description: relationship of which players belong to which team
** Relationship: one to many (one team have contain many players, players can only be on one team)
************************************************/
CREATE TABLE `player_team` (
	`pid` int(11) NOT NULL,
        `tid` int(11) NOT NULL,
        PRIMARY KEY (`pid`, `tid`),
        FOREIGN KEY (`pid`) REFERENCES `player` (`player_id`)
		ON DELETE CASCADE
                ON UPDATE CASCADE,
	FOREIGN KEY (`tid`) REFERENCES `team` (`team_id`)
		ON DELETE CASCADE
                ON UPDATE CASCADE
) ENGINE=InnoDB;


/************************************************
** Name: player_Conference
** Description: relationship of which players belong to which division
** Relationship: one to many (One division can contain many players, players can only belong to one divison)
************************************************/
CREATE TABLE `player_Conference` (
        `conference_pid` int(11) NOT NULL,
        `pid` int(11) NOT NULL,
        PRIMARY KEY (`conference_pid`, `pid`),
        FOREIGN KEY (`conference_pid`) REFERENCES `league_Conference` (`league_id`)
                ON DELETE CASCADE
                ON UPDATE CASCADE,
        FOREIGN KEY (`pid`) REFERENCES `player` (`player_id`)
                ON DELETE CASCADE
                ON UPDATE CASCADE
) ENGINE=InnoDB;


/************************************************
** Name: team_Conference
** Description: relationship of teams that belong to a division
** Relationship: one to many (one division may have many teams within it, teams can only belong to one division)
************************************************/
CREATE TABLE `team_Conference` (
        `conference_pid` int(11) NOT NULL,
        `tid` int(11) NOT NULL,
        PRIMARY KEY (`conference_pid`, `tid`),
        FOREIGN KEY (`conference_pid`) REFERENCES `league_Conference` (`league_id`)
                ON DELETE CASCADE
                ON UPDATE CASCADE,
        FOREIGN KEY (`tid`) REFERENCES `team` (`team_id`)
                ON DELETE CASCADE
                ON UPDATE CASCADE
) ENGINE=InnoDB;