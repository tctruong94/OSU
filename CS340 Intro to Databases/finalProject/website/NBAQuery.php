<?php
    if(isset($_POST['addPlayer']))
    {
        $servername = "oniddb.cws.oregonstate.edu";
        $username = "truontha-db";
        $password = "3MhWmVKgmVAK0U7H";
        $dbname = "truontha-db";
        
        
        $firstName = $_POST['firstNameofPlayer'];
        $lastName = $_POST['lastNameofPlayer'];
        $age = $_POST['playersAge'];
        $yearsPlayed = $_POST['playersYearsPlayed'];

        $conn = new mysqli($servername, $username, $password, $dbname);
        $stmt = $conn->prepare('INSERT INTO player (firstName_Player, lastName_Player, age, years_In_League) VALUES (?, ?, ?, ?)');
        $stmt->bind_param('ssii', $firstName, $lastName, $age, $yearsPlayed);
        $stmt->execute();
        $stmt->close();
        
        if ($conn->connect_error)
        {
            die("Connection failed: " . $conn->connect_error);
        }
        $conn->close();
    }


    if(isset($_POST['addTeam']))
    {
        $servername = "oniddb.cws.oregonstate.edu";
        $username = "truontha-db";
        $password = "3MhWmVKgmVAK0U7H";
        $dbname = "truontha-db";
        

        $firstName = $_POST['playerDropdown'];
        $newTeam = $_POST['teamDropdown'];

        $conn = new mysqli($servername, $username, $password, $dbname);

        $stmt = $conn->prepare('SELECT team_id FROM team WHERE team_name = ?');
        $stmt->bind_param('s', $newTeam);
        $stmt->execute();
        $stmt->bind_result($teamid);
        $results = $stmt->fetch();

        $conn2 = new mysqli($servername, $username, $password, $dbname);

        $stmt = $conn2->prepare('SELECT player_id FROM player WHERE firstName_Player = ?');
        $stmt->bind_param('s', $firstName);
        $stmt->execute();
        $stmt->bind_result($playerid);
        $results = $stmt->fetch();
    
        
        $conn3 = new mysqli($servername, $username, $password, $dbname);

        $stmt = $conn3->prepare('INSERT INTO player_team (tid, pid) VALUES (?, ?)');
        $stmt->bind_param('ss', $teamid, $playerid);
        
        $stmt->execute();
        $stmt->close();
        
        if ($conn->connect_error)
        {
            die("Connection failed: " . $conn->connect_error);
        }

        $conn->close();
    }

    
    if(isset($_POST['addPosition']))
    {
        $servername = "oniddb.cws.oregonstate.edu";
        $username = "truontha-db";
        $password = "3MhWmVKgmVAK0U7H";
        $dbname = "truontha-db";
        
        $firstName = $_POST['playerDropdown'];
        $newPos = $_POST['positionDropdown'];


        $conn = new mysqli($servername, $username, $password, $dbname);

        $stmt = $conn->prepare('SELECT player_id FROM player WHERE firstName_Player = (?)');
        $stmt->bind_param('i', $firstName);
        $stmt->execute();
        $stmt->bind_result($playerid);

        $results = $stmt->fetch();
        

        $conn2 = new mysqli($servername, $username, $password, $dbname);

        $stmt = $conn2->prepare('SELECT position_id FROM position WHERE pos_name = (?)');
        $stmt->bind_param('i', $newPos);
        $stmt->execute();
        $stmt->bind_result($positionid);

        $results = $stmt->fetch();
        

        $conn3 = new mysqli($servername, $username, $password, $dbname);

        $stmt = $conn3->prepare('INSERT INTO player_position (pid, pos_id) VALUES (?, ?)');
        $stmt->bind_param('ii', $playerid, $positionid);
        $stmt->execute();
        $stmt->close();
        

        if ($conn->connect_error) 
        {
            die("Connection failed: " . $conn->connect_error);
        }
        $conn->close();
    }
    

    if(isset($_POST['deletePlayer']))
    {
        $servername = "oniddb.cws.oregonstate.edu";
        $username = "truontha-db";
        $password = "3MhWmVKgmVAK0U7H";
        $dbname = "truontha-db";
        
        $firstName = $_POST['playerDropdown'];

        $conn = new mysqli($servername, $username, $password, $dbname);

        $stmt = $conn->prepare('DELETE FROM player WHERE firstName_Player = ?');
        $stmt->bind_param('s', $firstName);
        $stmt->execute();
        $stmt->close();
        
        if ($conn->connect_error) 
        {
            die("Connection failed: " . $conn->connect_error);
        }

        $conn->close();
    }
    header("Location:NBAMainPage.php");
    exit();
    ?>
