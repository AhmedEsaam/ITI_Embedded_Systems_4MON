<?php

if(isset($_GET['status']))
{
    $MyFile = fopen("LED_Status.txt", "w");
    
    if($_GET['status'] == 'on')
    {
        fwrite($MyFile, '1');
        header("Location: on.html");
    }
    elseif ($_GET['status'] == 'off') 
    {
        fwrite($MyFile, '0');
        header("Location: off.html");
    }

    fclose($MyFile);
}


?>