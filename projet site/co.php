<?php
$sqlHost='localhost';
$sqlUser='root';
$sqlPass='root';

$link = mysqli_connect($sqlHost,$sqlUser,$sqlPass, "commerce") or die ('Erreur '.mysqli_connect_error());
mysqli_set_charset ($link,"utf8");

//$reponses=array(mysqli_query($link ,"SELECT * FROM departements"), mysqli_query($link ,"SELECT sum(population_2010) FROM communes"), mysqli_query($link ,"SELECT count(*) FROM communes WHERE num_departement = 44 "), mysqli_query($link ,"SELECT * FROM communes ORDER BY surface ASC LIMIT 10"), mysqli_query($link ,"SELECT * FROM communes ORDER BY population_2010 DESC LIMIT 10"), mysqli_query($link ,"SELECT * FROM communes WHERE num_departement = 44 ORDER BY population_2010/surface DESC LIMIT 12"), mysqli_query($link ,"SELECT num_departement AS \"Numéro de département\", count(*) AS \"Nombre de communes\" FROM communes GROUP BY num_departement"));
$login = $_POST['login'];
$mdp = $_POST['mdp'];
if ($login == "ADMIN" and $mdp == "1234") {
	echo (file_get_contents('Ajouter Article.html'));
}
else {
	$donnees = mysqli_query($link, "SELECT * FROM clients WHERE login = '$login' AND mot_de_passe = '$mdp'");
	if (!$donnees) {
		$text = "Couple login / mot de passe non reconnu";
	}
	else {
		$donnees = mysqli_fetch_array($donnees);
		$text = "[Bienvenue $donnees[0]]";
	}
	$rep = mysqli_query($link ,"SELECT * FROM articles");
	$srt = "";
	while ($arr=mysqli_fetch_array($rep)) {
		$srt .= "<div class='article'>$arr[1]<input class=\"chiffres\" type=\"number\" name='$arr[0]' min=\"0\" max='$arr[2]' value=0><p id=\"prix\">$arr[4]€</p><p id=\"quantite\">Reste: $arr[2]</p></div>";
	}
	echo(str_replace('%php%', '<div class="article">'.$text."</div><form action='commander.php' method='post'><input type='hidden' name='login' value='$login'>".$srt."<input type='submit' class='bouton' id='commander' value='Passer la commande'></form>", str_replace('%cache%', "<input type='hidden' name='login' value='$login'>", file_get_contents('main_alternatif.html'))));
}
mysqli_close($link);
?>