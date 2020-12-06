<?php
$sqlHost='localhost';
$sqlUser='root';
$sqlPass='root';

$link = mysqli_connect($sqlHost,$sqlUser,$sqlPass, "commerce") or die ('Erreur '.mysqli_connect_error());
mysqli_set_charset ($link,"utf8");

$login = $_POST['login'];
$resultat= 0;
$requete_commandes = mysqli_query($link ,"SELECT * FROM commandes WHERE clef_client = '$login'");

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

echo(str_replace('%php%', "<div class='article' id='commande'>Votre coût total:<br>$resultat €</div>", str_replace('%cache%', "<input type='hidden' name='login' value='$login'>", file_get_contents('main_alternatif.html'))));
mysqli_close($link);
?>