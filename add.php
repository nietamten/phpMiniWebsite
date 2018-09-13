<?php

echo
"<!DOCTYPE html PUBLIC '-//W3C//DTD XHTML 1.0 Strict//EN'
  'http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd'>
<html xmlns='http://www.w3.org/1999/xhtml' xml:lang='pl'> 

<head>

<link rel='stylesheet'
    href='style.css'
    type='text/css'/>

</head>

<body>";
//pobranie katalogu z parametru albo defaultowy ($dir)
if ( isset( 	$_REQUEST['what'] ) )	
		$what = $_REQUEST['what']; 
else 	$what = 'pub';
	    
echo
"piszesz komentarz do: ".$what." <br><br>
<form id ='cos' action='tab.php?what=".$what."' method='post'>
	<input type='hidden' name='O' value='".$_REQUEST['o']."' />
	<input type='hidden' name='oo'/>
	tresc: <input type='text' name='cont' maxlength='300' /> \n
	nick: <input type='text' name='nick' maxlength='10'/>    \n
	<a href='javascript: submitform()'>Submit</a>
</form>

<script type='text/javascript'>

	function submitform()
	{
	    document.forms['cos'].submit();
	}

</script>
";
?>
