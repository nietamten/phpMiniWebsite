<?php

echo "
</body>
</html> 

<!DOCTYPE html PUBLIC '-//W3C//DTD XHTML 1.0 Strict//EN'
  'http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd'>
<html xmlns='http://www.w3.org/1999/xhtml' xml:lang='pl'>  

<head>

<link rel='stylesheet'
    href='style.css'
    type='text/css'/>

</head>

<body>
";

include 'lib.php';
$cont = $_POST[cont];
$what = $_REQUEST[what];
$nick = $_POST[nick];



if(true)
{
	sql("INSERT INTO komentarze (what, cont, nick)
	VALUES
	('$what','$cont','$nick') ");
	echo "OK\n";
}
else
	echo "blad, moze sproboj na innej przegladarce\n";



echo '<a href="index.php?what='.$_REQUEST[what].'">kliknij tutaj aby wrocic na strone</a> ';

?> 
</body>
</html> 
