<?php
$sqlHost='localhost';
$sqlUser='root';
$sqlPass='root';

$link = mysqli_connect($sqlHost,$sqlUser,$sqlPass, "commerce") or die ('Erreur '.mysqli_connect_error());
mysqli_set_charset ($link,"utf8");

$rep = mysqli_query($link ,"SELECT * FROM articles");
$srt = "";
while ($arr=mysqli_fetch_array($rep)) {
	$srt .= "<div class='article'>$arr[1]<p id=\"prix\">$arr[4]€</p><p id=\"quantite\">Reste: $arr[2]</p></div>";
}
echo(str_replace('%php%', $srt, file_get_contents('main.html')));
mysqli_close($link);
?>