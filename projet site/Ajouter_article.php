<?php
$sqlHost='localhost';
$sqlUser='root';
$sqlPass='root';

$link = mysqli_connect($sqlHost,$sqlUser,$sqlPass, "commerce") or die ('Erreur '.mysqli_connect_error());
mysqli_set_charset ($link,"utf8");

$ref = $_POST['ref'];
$nom = $_POST['nom'];
$quantite = $_POST['quantite'];
$prix_reviens = $_POST['pdr'];
$prix_vente = $_POST['pdv'];
if (strlen($ref) > 15) {
	echo ("Référence trop longue");
}
else if (strlen($nom) > 100) {
	echo ("Nom trop long");
}
else {
	mysqli_query($link ,"INSERT INTO articles VALUES ('$ref', '$nom', $quantite, $prix_reviens, $prix_vente)");
	echo (str_replace('</form>', '</form> <div class='article'>Article ajouté!</div>', file_get_contents('Ajouter Article.html')));
}
mysqli_close($link);
?>