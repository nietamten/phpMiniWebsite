<?php
function sql ($query)
{
 mysql_connect ("localhost", "login", "pass") or 
 die ("Nie mozna polaczyc z baza "); 
  
 mysql_select_db ("66395") or
 die ("nie mozna wybrac bazy");

if (!$wy=mysql_query($query))
  {
  die('Error: ' . mysql_error());
  }
//echo '<a href="index.php">sukces, kliknij tutaj aby wrocic na strone</a> "';

mysql_close();
return $wy;
};

function getIP() {
$ip;
if (getenv("HTTP_CLIENT_IP"))
$ip = getenv("HTTP_CLIENT_IP");
else if(getenv("HTTP_X_FORWARDED_FOR"))
$ip = getenv("HTTP_X_FORWARDED_FOR");
else if(getenv("REMOTE_ADDR"))
$ip = getenv("REMOTE_ADDR");
else
$ip = "UNKNOWN";
return $ip;
} 



?>