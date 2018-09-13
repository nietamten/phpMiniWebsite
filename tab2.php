<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="pl">  

<head>

<link rel="stylesheet"
    href="style.css"
    type="text/css"/>

</head>

<?php
$plik_tmp = $_FILES['plik']['tmp_name'];
$plik_nazwa = $_FILES['plik']['name'];
$plik_rozmiar = $_FILES['plik']['size'];	

if(is_uploaded_file($plik_tmp)) {
	if (end(explode('.',$plik_nazwa))=== "php" or end(explode('.',$plik_nazwa))=== "nfo")
           move_uploaded_file($plik_tmp, "pub/uploads/$plik_nazwa.txt");
        else
            move_uploaded_file($plik_tmp, "pub/uploads/$plik_nazwa");
        echo "Plik: <strong>$plik_nazwa</strong> o rozmiarze
             <strong>$plik_rozmiar bajtów</strong> zosta³ przes³any na serwer!";
        $file = fopen("pub/uploads/$plik_nazwa.nfo","w");
        fwrite($file,htmlentities($_POST['opis'],ENT_COMPAT,"ISO8859-1");
        fclose($file);
}
else
echo "Nie uda³o siê wys³aæ pliku <strong>$plik_nazwa</strong> na serwer";

echo '<br><br> 	<a href="index.php">kliknij tutaj aby wrocic na strone</a> "';

?>

</body>
</html> 
