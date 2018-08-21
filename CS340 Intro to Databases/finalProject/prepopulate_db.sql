/************************************************
** Name: Thanhbinh Truong
** Assignment: Final Project
** Class: CS340 Introduction to Database
** Date: March, 14th, 2018
************************************************/

/************************************************
** Script is used to pre-populate the NBA Database with some existing players and teams
************************************************/


/************************************************
** Description: insert players with their first name, last name, age and years in the league
************************************************/
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Russell", "Westbrook", 29, 9);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Paul", "George", 27, 7);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Andre", "Roberson", 26, 4);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Carmelo", "Anthony", 33, 14);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Steven", "Adams", 24, 4);

INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Lonzo", "Ball", 19, 1);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Brandon", "Ingram", 20, 1);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Josh", "Hart", 22, 1);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Isiah", "Thomas", 29, 6);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Brook", "Lopez", 29, 9);

INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Damian", "Lillard", 27, 5);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("CJ", "McCollum", 26, 4);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Jusuf", "Nurkic", 23, 3);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Evan", "Turner", 29, 7);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Shabazz", "Napier", 26, 3);

INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Stephen", "Curry", 29, 8);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Klay", "Thompson", 27, 6);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Kevin", "Durant", 29, 10);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Draymond", "Green", 27, 5);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Zaza", "Pachulia", 33, 14);


INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Giannis", "Antetokounmpo", 23, 4);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Eric", "Bledsoe", 28, 7);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Malcolm", "Brogdon", 25, 1);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Jabari", "Parker", 22, 3);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Thon", "Maker", 21, 1);

INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Ben", "Simmons", 21, 1);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Markelle", "Fultz", 19, 0);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Joel", "Embiid", 23, 3);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("JJ", "Reddick", 33, 11);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Dario", "Saric", 23, 1);


INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Kyle", "Lowry", 31, 11);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("DeMar", "DeRozan", 28, 8);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("OG", "Anunoby", 28, 3);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Serge", "Ibaka", 28, 8);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Jonas", "Valanciunas", 21, 2);

INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("John", "Wall", 27, 7);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Bradley", "Beal", 24, 5);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Otto", "Porter", 24, 4);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Markieff", "Morris", 28, 6);
INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES ("Marcin", "Gortat", 34, 10);


/************************************************
** Description: insert positions into table by their names
************************************************/
INSERT INTO position (pos_name) VALUES ("Point Guard");
INSERT INTO position (pos_name) VALUES ("Shooting Guard");
INSERT INTO position (pos_name) VALUES ("Small Forward");
INSERT INTO position (pos_name) VALUES ("Power Forward");
INSERT INTO position (pos_name) VALUES ("Center");


/************************************************
** Description: insert league divisons into table by their names and how many teams in each division
************************************************/
INSERT INTO league_Conference (conference_Name, num_teams) VALUES ("East", 4);
INSERT INTO league_Conference (conference_Name, num_teams) VALUES ("West", 4);


/************************************************
** Description: inserting teams into team's table by their city, name, and number of championships they have as a franchise
************************************************/
INSERT INTO team (team_name, city, number_of_Ships) VALUES ("Thunder", "Oklahoma", 0);
INSERT INTO team (team_name, city, number_of_Ships) VALUES ("Lakers", "Los Angeles", 16);
INSERT INTO team (team_name, city, number_of_Ships) VALUES ("TrailBlazers", "Portland", 2);
INSERT INTO team (team_name, city, number_of_Ships) VALUES ("Warriors", "Golden State", 5);


INSERT INTO team (team_name, city, number_of_Ships) VALUES ("Bucks", "Milwaukee", 1);
INSERT INTO team (team_name, city, number_of_Ships) VALUES ("76ers", "Philadelphia", 3);
INSERT INTO team (team_name, city, number_of_Ships) VALUES ("Raptors", "Toronto", 0);
INSERT INTO team (team_name, city, number_of_Ships) VALUES ("Wizards", "Washington", 1);


/************************************************
** Description: connect between which teams are in which division
************************************************/
INSERT INTO team_Conference (conference_pid, tid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT team_id FROM team WHERE team_name = "Thunder"));
INSERT INTO team_Conference (conference_pid, tid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT team_id FROM team WHERE team_name = "Lakers"));
INSERT INTO team_Conference (conference_pid, tid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT team_id FROM team WHERE team_name = "TrailBlazers"));
INSERT INTO team_Conference (conference_pid, tid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT team_id FROM team WHERE team_name = "Warriors"));


INSERT INTO team_Conference (conference_pid, tid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "East"), (SELECT team_id FROM team WHERE team_name = "Bucks"));
INSERT INTO team_Conference (conference_pid, tid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "East"), (SELECT team_id FROM team WHERE team_name = "76ers"));
INSERT INTO team_Conference (conference_pid, tid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "East"), (SELECT team_id FROM team WHERE team_name = "Raptors"));
INSERT INTO team_Conference (conference_pid, tid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT team_id FROM team WHERE team_name = "Wizards"));


/************************************************
** Description: connect between which players play which position(s)
************************************************/
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Russell"), (SELECT position_id FROM position WHERE pos_name = "Point Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Paul"), (SELECT position_id FROM position WHERE pos_name = "Shooting Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Andre"), (SELECT position_id FROM position WHERE pos_name = "Small Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Carmelo"), (SELECT position_id FROM position WHERE pos_name = "Power Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Steven"), (SELECT position_id FROM position WHERE pos_name = "Center"));

INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Lonzo"), (SELECT position_id FROM position WHERE pos_name = "Point Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Brandon"), (SELECT position_id FROM position WHERE pos_name = "Small Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Josh"), (SELECT position_id FROM position WHERE pos_name = "Shooting GUard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Isiah"), (SELECT position_id FROM position WHERE pos_name = "Point Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Brook"), (SELECT position_id FROM position WHERE pos_name = "Center"));

INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Damian"), (SELECT position_id FROM position WHERE pos_name = "Point Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "CJ"), (SELECT position_id FROM position WHERE pos_name = "Shooting Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Jusuf"), (SELECT position_id FROM position WHERE pos_name = "Small Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Evan"), (SELECT position_id FROM position WHERE pos_name = "Power Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Shabazz"), (SELECT position_id FROM position WHERE pos_name = "Point Guard"));

INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Stephen"), (SELECT position_id FROM position WHERE pos_name = "Point Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Klay"), (SELECT position_id FROM position WHERE pos_name = "Shooting Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Kevin"), (SELECT position_id FROM position WHERE pos_name = "Small Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Draymond"), (SELECT position_id FROM position WHERE pos_name = "Power Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Zaza"), (SELECT position_id FROM position WHERE pos_name = "Center"));


INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Giannis"), (SELECT position_id FROM position WHERE pos_name = "Small Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Eric"), (SELECT position_id FROM position WHERE pos_name = "Point Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Malcolm"), (SELECT position_id FROM position WHERE pos_name = "Small Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Jabari"), (SELECT position_id FROM position WHERE pos_name = "Power Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Thon"), (SELECT position_id FROM position WHERE pos_name = "Center"));

INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Ben"), (SELECT position_id FROM position WHERE pos_name = "Point Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Markelle"), (SELECT position_id FROM position WHERE pos_name = "Point Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Joel"), (SELECT position_id FROM position WHERE pos_name = "Center"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "JJ"), (SELECT position_id FROM position WHERE pos_name = "Shooting Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Dario"), (SELECT position_id FROM position WHERE pos_name = "Power Forward"));

INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Kyle"), (SELECT position_id FROM position WHERE pos_name = "Point Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "DeMar"), (SELECT position_id FROM position WHERE pos_name = "Shooting Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "OG"), (SELECT position_id FROM position WHERE pos_name = "Small Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Serge"), (SELECT position_id FROM position WHERE pos_name = "Power Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Jonas"), (SELECT position_id FROM position WHERE pos_name = "Center"));

INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "John"), (SELECT position_id FROM position WHERE pos_name = "Point Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Bradley"), (SELECT position_id FROM position WHERE pos_name = "Shooting Guard"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Otto"), (SELECT position_id FROM position WHERE pos_name = "Small Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Markieff"), (SELECT position_id FROM position WHERE pos_name = "Power Forward"));
INSERT INTO player_position (pid, pos_id) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Marcin"), (SELECT position_id FROM position WHERE pos_name = "Center"));



/************************************************
** Description: connect between which players are in which division
************************************************/
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT player_id FROM player WHERE firstName_Player = "Russell"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT player_id FROM player WHERE firstName_Player = "Paul"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT player_id FROM player WHERE firstName_Player = "Andre"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT player_id FROM player WHERE firstName_Player = "Carmelo"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT player_id FROM player WHERE firstName_Player = "Steven"));

INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT player_id FROM player WHERE firstName_Player = "Lonzo"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT player_id FROM player WHERE firstName_Player = "Brandon"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT player_id FROM player WHERE firstName_Player = "Josh"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT player_id FROM player WHERE firstName_Player = "Isiah"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT player_id FROM player WHERE firstName_Player = "Brook"));

INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT player_id FROM player WHERE firstName_Player = "Damian"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT player_id FROM player WHERE firstName_Player = "CJ"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT player_id FROM player WHERE firstName_Player = "Jusuf"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT player_id FROM player WHERE firstName_Player = "Evan"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT player_id FROM player WHERE firstName_Player = "Shabazz"));

INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT player_id FROM player WHERE firstName_Player = "Stephen"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT player_id FROM player WHERE firstName_Player = "Klay"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT player_id FROM player WHERE firstName_Player = "Kevin"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT player_id FROM player WHERE firstName_Player = "Draymond"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT player_id FROM player WHERE firstName_Player = "Zaza"));


INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "East"), (SELECT player_id FROM player WHERE firstName_Player = "Giannis"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "East"), (SELECT player_id FROM player WHERE firstName_Player = "Eric"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "East"), (SELECT player_id FROM player WHERE firstName_Player = "Malcolm"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "East"), (SELECT player_id FROM player WHERE firstName_Player = "Jabari"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "East"), (SELECT player_id FROM player WHERE firstName_Player = "Thon"));

INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "East"), (SELECT player_id FROM player WHERE firstName_Player = "Ben"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "East"), (SELECT player_id FROM player WHERE firstName_Player = "Markelle"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "East"), (SELECT player_id FROM player WHERE firstName_Player = "Joel"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "East"), (SELECT player_id FROM player WHERE firstName_Player = "JJ"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "East"), (SELECT player_id FROM player WHERE firstName_Player = "Dario"));

INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "East"), (SELECT player_id FROM player WHERE firstName_Player = "Kyle"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "East"), (SELECT player_id FROM player WHERE firstName_Player = "DeMar"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "East"), (SELECT player_id FROM player WHERE firstName_Player = "OG"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "East"), (SELECT player_id FROM player WHERE firstName_Player = "Serge"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "East"), (SELECT player_id FROM player WHERE firstName_Player = "Jonas"));

INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT player_id FROM player WHERE firstName_Player = "John"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT player_id FROM player WHERE firstName_Player = "Bradley"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT player_id FROM player WHERE firstName_Player = "Otto"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT player_id FROM player WHERE firstName_Player = "Markieff"));
INSERT INTO player_Conference (conference_pid, pid) VALUES ((SELECT league_id FROM league_Conference WHERE conference_Name = "West"), (SELECT player_id FROM player WHERE firstName_Player = "Marcin"));


/************************************************
** Description: connect between which players belong to which teams
************************************************/
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Russell"), (SELECT team_id FROM team WHERE team_name = "Thunder"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Paul"), (SELECT team_id FROM team WHERE team_name = "Thunder"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Andre"), (SELECT team_id FROM team WHERE team_name = "Thunder"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Carmelo"), (SELECT team_id FROM team WHERE team_name = "Thunder"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Steven"), (SELECT team_id FROM team WHERE team_name = "Thunder"));


INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Lonzo"), (SELECT team_id FROM team WHERE team_name = "Lakers"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Brandon"), (SELECT team_id FROM team WHERE team_name = "Lakers"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Josh"), (SELECT team_id FROM team WHERE team_name = "Lakers"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Isiah"), (SELECT team_id FROM team WHERE team_name = "Lakers"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Brook"), (SELECT team_id FROM team WHERE team_name = "Lakers"));

INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Damian"), (SELECT team_id FROM team WHERE team_name = "TrailBlazers"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "CJ"), (SELECT team_id FROM team WHERE team_name = "TrailBlazers"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Jusuf"), (SELECT team_id FROM team WHERE team_name = "TrailBlazers"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Evan"), (SELECT team_id FROM team WHERE team_name = "TrailBlazers"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Shabazz"), (SELECT team_id FROM team WHERE team_name = "TrailBlazers"));

INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Stephen"), (SELECT team_id FROM team WHERE team_name = "Warriors"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Klay"), (SELECT team_id FROM team WHERE team_name = "Warriors"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Kevin"), (SELECT team_id FROM team WHERE team_name = "Warriors"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Draymond"), (SELECT team_id FROM team WHERE team_name = "Warriors"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Zaza"), (SELECT team_id FROM team WHERE team_name = "Warriors"));

INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Giannis"), (SELECT team_id FROM team WHERE team_name = "Bucks"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Eric"), (SELECT team_id FROM team WHERE team_name = "Bucks"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Malcolm"), (SELECT team_id FROM team WHERE team_name = "Bucks"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Jabari"), (SELECT team_id FROM team WHERE team_name = "Bucks"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Thon"), (SELECT team_id FROM team WHERE team_name = "Bucks"));

INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Ben"), (SELECT team_id FROM team WHERE team_name = "76ers"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Markelle"), (SELECT team_id FROM team WHERE team_name = "76ers"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Joel"), (SELECT team_id FROM team WHERE team_name = "76ers"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "JJ"), (SELECT team_id FROM team WHERE team_name = "76ers"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Dario"), (SELECT team_id FROM team WHERE team_name = "76ers"));

INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Kyle"), (SELECT team_id FROM team WHERE team_name = "Raptors"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "DeMar"), (SELECT team_id FROM team WHERE team_name = "Raptors"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "OG"), (SELECT team_id FROM team WHERE team_name = "Raptors"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Serge"), (SELECT team_id FROM team WHERE team_name = "Raptors"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Jonas"), (SELECT team_id FROM team WHERE team_name = "Raptors"));

INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "John"), (SELECT team_id FROM team WHERE team_name = "Wizards"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Bradley"), (SELECT team_id FROM team WHERE team_name = "Wizards"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Otto"), (SELECT team_id FROM team WHERE team_name = "Wizards"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Markieff"), (SELECT team_id FROM team WHERE team_name = "Wizards"));
INSERT INTO player_team (pid, tid) VALUES ((SELECT player_id FROM player WHERE firstName_Player = "Marcin"), (SELECT team_id FROM team WHERE team_name = "Wizards"));

