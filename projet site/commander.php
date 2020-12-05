<?php
$sqlHost='localhost';
$sqlUser='root';
$sqlPass='root';

$link = mysqli_connect($sqlHost,$sqlUser,$sqlPass, "commerce") or die ('Erreur '.mysqli_connect_error());
mysqli_set_charset ($link,"utf8");

$login = $_POST['login'];
$refs = mysqli_query($link ,"SELECT reference FROM articles");
$commandes = array();
while ($res=mysqli_fetch_array($refs)) { //Etrangement, $res est une liste qui contient 2 fois la référence en traitement.
	$quantite = $_POST[$res[0]]; //De ce fait, nous sommes obligés d'utiliser $res[0].
	if ($quantite != 0) {
		array_push($commandes, array($res[0], $quantite));
	}
}
date_default_timezone_set("Europe/Paris");
$date = getdate();
$str_date = $date['year']."-".$date['mon']."-".$date['mday'];
mysqli_query($link ,"INSERT INTO commandes (date, clef_client) VALUES ('$str_date', '$login')");
$id_commande = mysqli_fetch_array(mysqli_query($link ,"SELECT numero FROM commandes WHERE clef_client = '$login' ORDER BY numero DESC LIMIT 1"))[0];
foreach ($commandes as &$comm) {
	$i = 0;
	while ($i < $comm[1]) {
		$indicateur = mysqli_query($link ,"INSERT INTO relations (clef_article, clef_commande) VALUES ('$comm[0]', '$id_commande')");
		$i += 1;
	}
	$nbre_articles_avant = mysqli_fetch_array(mysqli_query($link ,"SELECT quantite FROM articles WHERE reference = '$comm[0]'"))[0];
	$nbre_articles_apres = intval($nbre_articles_avant) - intval($comm[1]);
	mysqli_query($link ,"UPDATE `articles` SET `quantite` = '$nbre_articles_apres' WHERE `articles`.`reference` = '$comm[0]';");
}
$rep = mysqli_query($link ,"SELECT * FROM articles");
$srt = "<div class='article'>[Commande passée avec succès!]</div>";
while ($arr=mysqli_fetch_array($rep)) {
	$srt .= "<div class='article'>$arr[1]<p id=\"prix\">$arr[4]€</p><p id=\"quantite\">Reste: $arr[2]</p></div>";
}
echo(str_replace('%php%', $srt, str_replace('%cache%', "<input type='hidden' name='login' value='$login'>", file_get_contents('main_alternatif.html'))));
echo($srt);
mysqli_close($link);
?>