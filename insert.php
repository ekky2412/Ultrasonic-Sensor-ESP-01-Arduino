<?php
    $dbname = "iot_ultrasonic";
    $dbuser = "root";
    $dbpass = "";
    $dbhost = "localhost";
    $conn = mysqli_connect($dbhost,$dbuser,$dbpass,$dbname);

    if(!$conn){
        echo "Error : " . mysqli_connect_error();
        exit();
    }

    if(isset($_GET["jarak"])){
        $stmt = $conn->prepare("INSERT INTO sensor (jarak) VALUES (?)");
        $stmt->bind_param("d",$_GET["jarak"]);
        $stmt->execute();
        $stmt->close();
        echo "ok";
    }
    else{
        echo "no data inserted";
    }
?>