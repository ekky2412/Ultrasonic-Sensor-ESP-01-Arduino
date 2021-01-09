<!-- <?php
    $jarak = $_GET['jarak'];
?> -->
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <meta http-equiv="refresh" content="3">

        <title>Jarak</title>
    </head>
    <body>
        <!-- <h1>Jarak : <?= $jarak ?> cm</h1> -->

        <div class = "container" > 
                <h3><u>Coba tampilin data</u></h3>
                <!-- <p><strong>Klik tombolnya dulu buat nampilin data</strong></p>  -->
                <div id="records"></div> 
                <!-- <p>
                    <input type="button" id = "getdata" value = "Fetch Records" />
                </p> -->
        </div> 
        
        <script src="http://code.jquery.com/jquery-3.1.1.min.js"></script>
        <script src="getAJAX.js"></script>
    </body>
</html>