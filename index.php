<?php

// header('Content-Type: html/plain');
//header("Content-Security-Policy: script-src 'self'");


function lastMod($dir,$date){
	$date_ = $date;
    $files = scandir($dir);

    foreach($files as $key => $value){
        $path = realpath($dir.DIRECTORY_SEPARATOR.$value);

        if(!is_dir($path)) {
            if(filemtime($path)>$date)
            {
               	if (filemtime($path)>$date_)
					$date_ = filemtime($path);
			}
        } else if($value != "." && $value != "..") {
            $date__ = lastMod($path, $results);
			if ($date__>$date_)
				$date_ = $date__;
        }
    }
	return $date_;
}

//koncowki naw plikow ktorych poczatki wyswietlac na stronie jako opis
$roz = array('c','pas','asm','java','css','sh','cpp'); 
//poczatek opisu
$wstep = "";
//opis
$tresc = "";
//informacje
$info = "";
//unikalna nazwa dla zbioru komentarzy
$comm = "";
  
//pobranie katalogu z parametru, jesli brak to defaultowy
if ( isset($_REQUEST['dir']) )
	$dir = $_REQUEST['dir']; 
    else $dir= 'pub';

	$comm = $dir;
	
//jesli jest parametr file to pobieram opis pliku
if ( isset($_REQUEST['file']) ){
	$file = $_REQUEST['file'];
	
	$comm = $file;
	
    $end = end(explode('.',$file));
    
$info = 'NAZWA: '.substr($file,strrpos($file,'/')+1).' ROZMIAR: '.
	filesize($file).'B OSTATNIO ZMIENIONY: '.date("Y m d",filemtime($file)).'<a href="'.$file.'">  -->POBIERZ</a>' ;
	
	if (file_exists($file.'.nfo')){
		$f = fopen ($file.'.nfo','r');
     $tresc = fread($f,10000);
     fclose($f);    
     $wstep = "OPIS PLIKU:";
     
} else
//jezeli plik ma odpowiednie rozszezenie to wstawiam jego poczatek do opisu
if ( in_array($end,$roz) ) {
	$f = fopen($file,'r');
	$tresc = fread($f,600);
	$tresc = htmlentities($tresc,ENT_COMPAT,"ISO8859-1");
	fclose($f);
	$wstep = "POCZATEK PLIKU:";
    } else{
   $wstep = '----- PLIK BEZ OPISU-----';  
   $tresc = ""; 
	}	
//jezeli nie ma parametru file to wstawia ewentualny opis katalogu z pliku .nfo    
}else{
	$info = 'aktualny katalog: "'. $dir.'"';
    if (file_exists($dir.'.nfo')){
     $f = fopen ($dir.'.nfo','r');
     $tresc = fread($f,10000);
     fclose($f);
      $wstep = "OPIS KATALOGU:";
    }else{
    $wstep = '-----KATALOG BEZ OPISU-----';
    $tresc = ""; 
    }

    if($dir=='pub')
    $tresc = 'OSTATNIA ZMIANA NA CALEJ STRONIE: '.date("Y m d",lastMod('pub',0)).'<br><br>'.$tresc;
}


echo '
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="pl">  
<head>

  <title>ble</title>

<meta http-equiv="content-language" content="pl"/>
<meta http-equiv="content-type" content="text/html" charset="iso-8859-2" />
<meta name="robots" content="index, follow" />
<meta name="keywords" content="programowanie, kody ¼ród³owe, source, examples" />
<meta name="author" content="ble"/> 
<meta http-equiv="reply-to" content="nietamten@gmail.com"/> 
<meta name="title" content="'.$dir.'"/>
<meta name="description" content="';
if ($dir != 'pub') echo htmlentities($tresc);
echo'"/>
<style> #ATH, #ath { width: auto !important; } </style>
<link rel="stylesheet"
    href="style.css"
    type="text/css"/>
</head>

<body>
<h1> ble </h1>
<!-- blok z cala trescia -->
<div id="all">';
  
echo "\n",'<!-- blok z opisem -->'.
"\n",'<div id="desc">';

	echo $info.'<br/><br/>';
	echo $wstep.'<br/><br/>';
	#echo '<code>'.$tresc.'</code>';
	echo $tresc;

echo "\n",'</div>';

echo "\n",'<!-- blok do wyboru pliku/katalogu -->'.
"\n",'<div id="fmgr">'."\n";

//jezeli katalog nie istnieje wyswietl blad
if ( !file_exists($dir) ){
    echo '<h1> brak katalogu '.$dir.' </h1>';
    return;
}   
    
//jesli katalog nie jest defaultowym (najwyzszym) to dodaje link do wyjscia katalog wyzej
    if ( $dir != 'pub'){
    echo "\n".'<div class="dir">'."\n".
	'<a href="index.php?dir='.substr($dir,0,strrpos($dir,'/')) .'">..</a>'.
	"\n",'</div>'."\n";
    }
    
//pobranie listingu katalogu    
    $list = glob($dir.'/'.'*');

//petla przetwarzajaca listing katalogu na linki
    foreach ($list as $filefl){
//jezeli katalog to dodaj link ktory do niego przechodzi
	if (is_dir($filefl)){
	    echo '<div class="dir">'."\n".
		'<a href="index.php?dir='.$filefl.'">','->', substr($filefl,strrpos($filefl,'/')+1).'</a>'.
		"\n",'</div>'."\n";
//jesli plik to pomin wszystkie .nfo(w nich sa opisy) i dodaj linki 
	}else{
	if ( end(explode('.',$filefl)) != 'nfo'){
	    echo '<div class="file">'.'<a href="index.php?dir=',$dir,'&file=',$filefl,'">'.
		'~'. htmlentities(substr($filefl,strrpos($filefl,'/')+1),ENT_COMPAT,"ISO8859-1")."</a>\n".
		'</div>'."\n";                   
	    }
	}
    }
//div konczacy 'fmgr'
echo "\n".'</div>'."\n";

    
echo "\n",'<!-- blok z komentarzem -->'.
"\n",'<div id="comment">';

echo "\nKomentarze:\n ";


echo '<span class="p"><a href="add.php?what=',$comm,'&o=',$O,'">->Skomentuj</a></span>';


///////////SQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQL
include 'lib.php';

$wyn = sql("SELECT * FROM komentarze WHERE what='$comm' ORDER BY id DESC");

if ( mysql_num_rows($wyn) > 0 ) {
echo "<table border='1'>
<tr>
<th>kto</th>
<th>co</th>
<th>kiedy</th>
</tr>";

while($row = mysql_fetch_array($wyn))
  {
  echo "<tr>\n";
  echo "<td>" . $row['nick'] . "</td>\n";
  echo "<td>" . $row['cont'] . "</td>\n";
  echo "<td>" . $row['time'] . "</td>\n";
  echo "</tr>\n";
  }
echo "</table>";

}

/////////////SQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQL

//div komentarza
echo "\n".'</div>'."\n";


//div konczacy 'all'
echo '</div>';

?>                

</body>
</html>
