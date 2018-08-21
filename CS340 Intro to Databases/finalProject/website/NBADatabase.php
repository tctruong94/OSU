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

    $sql = "SELECT player_id, firstName_Player, lastName_Player, age, years_In_League FROM player";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) 
    {
        echo '<table cellpadding="1" cellspacing="0.5" class="player-table" border="solid">';
        echo '<tr><th>Player</th><th>First Name</th><th>Last Name</th><th>Age</th><th>Years Played</th></tr>';

        while($row = $result->fetch_assoc()) 
        {
            echo '<tr>';
            
            foreach($row as $key=>$value) 
            {
                echo '<td>',$value,'</td>';
            }
            echo '</tr>';
        }

        echo '</table><br />';
    } else 
    {
        echo "0 results";
    }
    $conn->close();
    ?>
