$(function(){ 
    $(window).on('load', function(){ 
        $.ajax({ 
            method: "GET", 
            url: "getrecords_ajax.php",
        }).done(function( data ) { 
            let result= $.parseJSON(data); 
            let string='<table width="100%"><tr><th>Jarak</th> <th>Waktu</th><tr>';

            /* from result create a string of data and append to the div */
            $.each( result, function( key, value ){    
                string += "<tr> <td>"+value['jarak']+"</td> <td>"+value['waktu']+"</td> </tr>"; 
            }); 
            string += '</table>'; 
            $("#records").html(string); 
        }); 
    }); 
}); 
