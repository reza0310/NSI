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
	$resultat= 0;
	$requete_commandes = mysqli_query($link ,"SELECT * FROM commandes");
	while ($commande=mysqli_fetch_array($requete_commandes)) {
		$requete_relation=mysqli_query($link, "SELECT clef_article FROM relations WHERE clef_commande='$commande[0]' ");
		
		while ($relation=mysqli_fetch_array($requete_relation)) {
			$truc = mysqli_query($link ,"SELECT prix_de_vente FROM articles WHERE reference= '$relation[0]'");
			if (!$truc) {
				printf("Error: %s\n", mysqli_error($link));
				exit();
			}
			$prix_de_article= mysqli_fetch_array($truc)[0];
			$resultat+= $prix_de_article;
		}
	}
	echo (str_replace('</form>', "</form> <div class='article'>Article ajouté!</div>", str_replace("%chiffre%", "Votre chiffre d'affaire est de: ".$resultat."€", file_get_contents('Ajouter Article.html'))));
}
mysqli_close($link);
?>