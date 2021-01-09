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
        // echo '<script type="text/javascript"  src="getAJAX.js"></script>';
        $stmt->bind_param("d",$_GET["jarak"]);
        $stmt->execute();
        $stmt->close();
        echo "ok";
        // refreshData();
        // header("Location: index.php;", true, 303);
    }
    else{
        echo "no data inserted";
    }
?>