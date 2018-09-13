<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="pl">  

<head>

<link rel="stylesheet"
    href="style.css"
    type="text/css"/>

</head>

<body>

<div>
<form enctype="multipart/form-data" action="tab2.php" method="POST">
<!-- <input type="hidden" name="MAX_FILE_SIZE" value="200000" /> -->
<input name="plik" type="file" />
<input type="submit" value="Wy¶lij plik" />
opis: <input type="text" name="opis" maxlength="1000"/>
</form>
</div>

<br><br>
hosting ma tylko 50 mb z czego strona zajmuje niecale 2mb a baza danych rosnie, polecam zip'y, wyslane plik zamieszczane sa w katalogu 'uploads'
</body>
</html>

