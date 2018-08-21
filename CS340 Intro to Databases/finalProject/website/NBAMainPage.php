<!DOCTYPE html>
<html>
    <head>
    <meta charset="UTF-8">
        <title>NBA DATABASE</title>
        <link rel="stylesheet" href="css/style.css">
        <link rel="stylesheet" href="css/bootstrap.min.css">
        <link rel="stylesheet" href="css/bootstrap-theme.min.css">
        <script src="javascript/jquery.min.js"></script>
        <script src="javascript/bootstrap.min.js"></script>
    </head>
    <body>
        <div id="topTitle" class="jumbotron">
            <h1>NATIONAL BASKETBALL ASSOCIATION SAMPLE DATABASE</h1>
        </div>
        <div>
            <div class="container-fluid">
                <center>
                    <form action="NBAMainPage.php" method="POST">
                    Select a Player: <select id = "playerDropdown" name = "playerDropdown">
<?php
    $servername = "oniddb.cws.oregonstate.edu";
    $username = "truontha-db";
    $password = "3MhWmVKgmVAK0U7H";
    $dbname = "truontha-db";

    $conn = new mysqli($servername, $username, $password, $dbname);

    if ($conn->connect_error)
    {
        die("Connection failed: " . $conn->connect_error);
    }
    $sql = "SELECT firstName_Player FROM player";
    $result = $conn->query($sql);
    while ($row = $result->fetch_assoc())
    {
        unset($firstName);
        $firstName = $row['firstName_Player'];
        echo '<option value="'.$firstName.'">'.$firstName.'</option>';
    }
    $conn->close();
    ?>
</select>

<input name="playerChoose" type="submit" class="btn-primary" value="Player Chosen"/>
                    </form>
                </center>
            </div>
        </div>

<div id="tableHolder"><center>
<table class="table"  cellspacing="40">
    <tr>
        <th>Player ID</th>
        <th>First Name</th>
        <th>Last Name</th>
        <th>Age</th>
        <th>Years in league</th>
        <th>Team</th>
        <th>Position</th>
    </tr>
<tr>
<td>
<?php
    if(isset($_POST['playerChoose']))
    {
        $servername = "oniddb.cws.oregonstate.edu";
        $username = "truontha-db";
        $password = "3MhWmVKgmVAK0U7H";
        $dbname = "truontha-db";
        
        $firstName = $_POST['playerDropdown'];

        $conn = new mysqli($servername, $username, $password, $dbname);

        $stmt = $conn->prepare('SELECT player_id FROM player WHERE firstName_Player=?');
        $stmt->bind_param('s', $firstName);
        $stmt->execute();
        $stmt->bind_result($playerID);

        $results = $stmt->fetch();
        echo $playerID;

        $stmt->close();
        
        if ($conn->connect_error)
        {
            die("Connection failed: " . $conn->connect_error);
        }
        $conn->close();
    }
    ?>
</td>
<td>
<?php
    if(isset($_POST['playerChoose']))
    {
        $servername = "oniddb.cws.oregonstate.edu";
        $username = "truontha-db";
        $password = "3MhWmVKgmVAK0U7H";
        $dbname = "truontha-db";
        
        $name = $_POST['playerDropdown'];

        $conn = new mysqli($servername, $username, $password, $dbname);

        $stmt = $conn->prepare('SELECT firstName_Player FROM player WHERE firstName_Player=?');
        $stmt->bind_param('s', $firstName);
        $stmt->execute();
        $stmt->bind_result($playerFN);
        $results = $stmt->fetch();
        echo $playerFN;
        $stmt->close();
        
        if ($conn->connect_error)
        {
            die("Connection failed: " . $conn->connect_error);
        }
        $conn->close();
    }
    ?>
</td>
<td>
<?php
    if(isset($_POST['playerChoose']))
    {
        $servername = "oniddb.cws.oregonstate.edu";
        $username = "truontha-db";
        $password = "3MhWmVKgmVAK0U7H";
        $dbname = "truontha-db";
        
        $name = $_POST['playerDropdown'];

        $conn = new mysqli($servername, $username, $password, $dbname);

        $stmt = $conn->prepare('SELECT lastName_Player FROM player WHERE firstName_Player=?');
        $stmt->bind_param('s', $firstName);
        $stmt->execute();
        $stmt->bind_result($playerLN);
        $results = $stmt->fetch();
        echo $playerLN;
        $stmt->close();
        
        if ($conn->connect_error)
        {
            die("Connection failed: " . $conn->connect_error);
        }
        $conn->close();
    }
    ?>
</td>
<td>
<?php
    if(isset($_POST['playerChoose']))
    {
        $servername = "oniddb.cws.oregonstate.edu";
        $username = "truontha-db";
        $password = "3MhWmVKgmVAK0U7H";
        $dbname = "truontha-db";
        
        $name = $_POST['playerDropdown'];

        $conn = new mysqli($servername, $username, $password, $dbname);

        $stmt = $conn->prepare('SELECT age FROM player WHERE firstName_Player=?');
        $stmt->bind_param('s', $firstName);
        $stmt->execute();
        $stmt->bind_result($playersAge);
        $results = $stmt->fetch();
        echo $playersAge;
        $stmt->close();
        
        if ($conn->connect_error)
        {
            die("Connection failed: " . $conn->connect_error);
        }
        $conn->close();
    }
    ?>
</td>
<td>
<?php
    if(isset($_POST['playerChoose']))
    {
        $servername = "oniddb.cws.oregonstate.edu";
        $username = "truontha-db";
        $password = "3MhWmVKgmVAK0U7H";
        $dbname = "truontha-db";
        
        $name = $_POST['playerDropdown'];

        $conn = new mysqli($servername, $username, $password, $dbname);

        $stmt = $conn->prepare('SELECT years_In_League FROM player WHERE firstName_Player=?');
        $stmt->bind_param('s', $firstName);
        $stmt->execute();
        $stmt->bind_result($playerEXP);
        $results = $stmt->fetch();
        echo $playerEXP;
        $stmt->close();
        
        if ($conn->connect_error)
        {
            die("Connection failed: " . $conn->connect_error);
        }
        $conn->close();
    }
    ?>
</td>
<td>
<?php
    if(isset($_POST['playerChoose']))
    {
        $servername = "oniddb.cws.oregonstate.edu";
        $username = "truontha-db";
        $password = "3MhWmVKgmVAK0U7H";
        $dbname = "truontha-db";
        
        $name = $_POST['playerChoose'];

        $conn = new mysqli($servername, $username, $password, $dbname);

        $stmt = $conn->prepare('SELECT team_name FROM team
                               INNER JOIN player_team
                               ON team.team_id = player_team.tid
                               INNER JOIN player
                               ON player_team.pid = player.player_id
                               WHERE player.firstName_Player = ?');
        $stmt->bind_param('s', $firstName);
        $stmt->execute();
                               
        if ($conn->connect_error)
        {
            die("Connection failed: " . $conn->connect_error);
        }
                               
                               
        $team = "";
        $stmt->bind_result($team);
                               
        while ($stmt->fetch())
        {
            echo $team."<br>";
        }
                               
        $stmt->close();
        $conn->close();
}
?>
</td>
<td>
<?php
    if(isset($_POST['playerChoose']))
    {
        $servername = "oniddb.cws.oregonstate.edu";
        $username = "truontha-db";
        $password = "3MhWmVKgmVAK0U7H";
        $dbname = "truontha-db";
        
        $name = $_POST['playerChoose'];

        $conn = new mysqli($servername, $username, $password, $dbname);

        $stmt = $conn->prepare('SELECT pos_name FROM position
                               INNER JOIN player_position
                               ON position.position_id = player_position.pos_id
                               INNER JOIN player
                               ON player_position.pid = player.player_id
                               WHERE player.firstName_Player = ?');
                               $stmt->bind_param('s', $firstName);
                               $stmt->execute();
                               
    if ($conn->connect_error)
    {
        die("Connection failed: " . $conn->connect_error);
    }                       
                               
    $position = "";
    $stmt->bind_result($position);
                               
    while ($stmt->fetch())
    {
        echo $position."<br>";
    }
                               
    $stmt->close();
    $conn->close();
}
?>
</tr>
</td>
</tr>
</table>
</center>
</div>

<div>
    <center>
        <div class="container-fluid">
            <form name="addPlayerForm" action='NBAQuery.php' method='POST'>
            First Name: <input type="text" id="firstNameofPlayer" name ="firstNameofPlayer" value="" >
            Last Name: <input type="text" id="lastNameofPlayer" name ="lastNameofPlayer" value="" >
            Age: <input type="number" id="playersAge" name="playersAge" value="" onfocus="if (this.value=='Player Age') this.value='';"/>
            Years in League: <input type="number" id="playersYearsPlayed" name="playersYearsPlayed" value="" onfocus="if (this.value=='Player Experience') this.value='';"/>
            <input name="addPlayer" type="submit" class="btn-primary" value="Add New Player"/>
            </form>
        </div>
    </center>
</div>

<div>
<div class="container-fluid">
<form action='NBAQuery.php' method='POST'>
<br>
<br>
Delete Player: 
<select id = "playerDropdown" name = "playerDropdown">
<?php
    $servername = "oniddb.cws.oregonstate.edu";
    $username = "truontha-db";
    $password = "3MhWmVKgmVAK0U7H";
    $dbname = "truontha-db";

    $conn = new mysqli($servername, $username, $password, $dbname);

    if ($conn->connect_error)
    {
        die("Connection failed: " . $conn->connect_error);
    }
    $sql = "SELECT firstName_Player FROM player";
    $result = $conn->query($sql);
    while ($row = $result->fetch_assoc()) 
    {
        unset($firstName);
        $firstName = $row['firstName_Player'];
        echo '<option value="'.$firstName.'">'.$firstName.'</option>';
    }
    $conn->close();
    ?>
</select>
<input name="deletePlayer" type="submit" class="btn-primary" value="Delete"/>
</form>
</div>
</div>
<div>
<div class="container-fluid">
<form action='NBAQuery.php' method = 'POST'>
<br>
<br>
Add <select id = "playerDropdown" name = "playerDropdown">
<?php
    $servername = "oniddb.cws.oregonstate.edu";
    $username = "truontha-db";
    $password = "3MhWmVKgmVAK0U7H";
    $dbname = "truontha-db";

    $conn = new mysqli($servername, $username, $password, $dbname);

    if ($conn->connect_error) 
    {
        die("Connection failed: " . $conn->connect_error);
    }
    $sql = "SELECT firstName_Player FROM player";
    $result = $conn->query($sql);
    while ($row = $result->fetch_assoc())
    {
        unset($firstName);
        $firstName = $row['firstName_Player'];
        echo '<option value="'.$firstName.'">'.$firstName.'</option>';
    }
    $conn->close();
    ?>
</select>
to the <select id = "teamDropdown" name = "teamDropdown">
<?php
    $servername = "oniddb.cws.oregonstate.edu";
    $username = "truontha-db";
    $password = "3MhWmVKgmVAK0U7H";
    $dbname = "truontha-db";

    $conn = new mysqli($servername, $username, $password, $dbname);

    if ($conn->connect_error)
    {
        die("Connection failed: " . $conn->connect_error);
    }
    $sql = "SELECT team_name FROM team";
    $result = $conn->query($sql);
    while ($row = $result->fetch_assoc())
    {
        unset($newTeam);
        $newTeam = $row['team_name'];
        echo '<option value="'.$newTeam.'">'.$newTeam.'</option>';
    }
    $conn->close();
    ?>
</select>
<input name="addTeam" type="submit" class="btn-primary" value="Update"/>
</form>
</div>
</div>
<div>
<div class="container-fluid">
<form action='NBAQuery.php' method = 'POST'>
<br>
<br>
Add
<select id = "positionDropdown" name = "positionDropdown">
<?php
    $servername = "oniddb.cws.oregonstate.edu";
    $username = "truontha-db";
    $password = "3MhWmVKgmVAK0U7H";
    $dbname = "truontha-db";

    $conn = new mysqli($servername, $username, $password, $dbname);

    if ($conn->connect_error)
    {
        die("Connection failed: " . $conn->connect_error);
    }
    $sql = "SELECT pos_name FROM position";
    $result = $conn->query($sql);
    while ($row = $result->fetch_assoc())
    {
        unset($newPos);
        $newPos = $row['pos_name'];
        echo '<option value="'.$newPos.'">'.$newPos.'</option>';
    }
    $conn->close();
    ?>
</select>
position to <select id = "playerDropdown" name = "playerDropdown">
<?php
    $servername = "oniddb.cws.oregonstate.edu";
    $username = "truontha-db";
    $password = "3MhWmVKgmVAK0U7H";
    $dbname = "truontha-db";

    $conn = new mysqli($servername, $username, $password, $dbname);

    if ($conn->connect_error)
    {
        die("Connection failed: " . $conn->connect_error);
    }
    $sql = "SELECT firstName_Player FROM player";
    $result = $conn->query($sql);
    while ($row = $result->fetch_assoc())
    {
        unset($firstName);
        $firstName = $row['firstName_Player'];
        echo '<option value="'.$firstName.'">'.$firstName.'</option>';
    }
    $conn->close();
    ?>
</select>
<input name="addPosition" type="submit" class="btn-primary" value="Update"/>
</form>
</div>
</div>

<div>
<br/><br/>
</div>
</body>
</html>
