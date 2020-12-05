<?php
$sqlHost='localhost';
$sqlUser='root';
$sqlPass='root';

$link = mysqli_connect($sqlHost,$sqlUser,$sqlPass, "commerce") or die ('Erreur '.mysqli_connect_error());
mysqli_set_charset ($link,"utf8");

$login = $_POST['login'];
$srt = "";
$requete_commandes = mysqli_query($link ,"SELECT * FROM commandes WHERE clef_client = '$login'");
while ($commande=mysqli_fetch_array($requete_commandes)) {
	$srt .= "<div class='article' id='commande'>Commande n°$commande[0] passée le $commande[1]:<br>";
	$requete_relations = mysqli_query($link ,"SELECT * FROM relations WHERE clef_commande = '$commande[0]' GROUP BY clef_article");
	while ($relation=mysqli_fetch_array($requete_relations)) {
		$nombre = mysqli_fetch_array(mysqli_query($link ,"SELECT count(*) FROM relations WHERE clef_commande = '$commande[0]' AND clef_article = '$relation[1]'"))[0];
		$nom = mysqli_fetch_array(mysqli_query($link ,"SELECT nom FROM articles WHERE reference = '$relation[1]'"))[0];
		$srt .= "-$nombre x $nom<br>";
	}
	$srt .= "</div>";
}
echo(str_replace('%php%', $srt, file_get_contents('main.html')));
mysqli_close($link);
?>