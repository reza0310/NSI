<?php
$sqlHost='localhost';
$sqlUser='root';
$sqlPass='root';

$link = mysqli_connect($sqlHost,$sqlUser,$sqlPass, "geographie") or die ('Erreur '.mysqli_connect_error());
mysqli_set_charset ($link,"utf8");
$reponse=mysqli_query ( $link ,"SELECT * FROM departements"  ) ;
while ($res=mysqli_fetch_array($reponse))
	{
	$numdep=$res[0];
	$nom=$res[2];
	echo imap_utf8 ("Le numéro du département $nom est $numdep <br>");
	}

mysqli_close($link);

?>
