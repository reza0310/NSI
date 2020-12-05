<?php
$sqlHost='localhost';
$sqlUser='root';
$sqlPass='root';

$link = mysqli_connect($sqlHost,$sqlUser,$sqlPass, "commerce") or die ('Erreur '.mysqli_connect_error());
mysqli_set_charset ($link,"utf8");

//$reponses=array(mysqli_query($link ,"SELECT * FROM departements"), mysqli_query($link ,"SELECT sum(population_2010) FROM communes"), mysqli_query($link ,"SELECT count(*) FROM communes WHERE num_departement = 44 "), mysqli_query($link ,"SELECT * FROM communes ORDER BY surface ASC LIMIT 10"), mysqli_query($link ,"SELECT * FROM communes ORDER BY population_2010 DESC LIMIT 10"), mysqli_query($link ,"SELECT * FROM communes WHERE num_departement = 44 ORDER BY population_2010/surface DESC LIMIT 12"), mysqli_query($link ,"SELECT num_departement AS \"Numéro de département\", count(*) AS \"Nombre de communes\" FROM communes GROUP BY num_departement"));
$login = $_POST['login'];
$mdp = $_POST['mdp'];
$mail = $_POST['mail'];
$adresse = $_POST['adresse'];
$repons = mysqli_query($link ,"SELECT * FROM clients");
/*if (!$repons) {
    printf("Error: %s\n", mysqli_error($link));
    exit();
}*/
$test_bool = 0;
while ($res=mysqli_fetch_array($repons)) {
	if ($login == $res[0]) {
		$test_bool = 1;
	}
}
if ($test_bool == 1) {
	echo ("Login déjà pris");
}
else {
	mysqli_query($link ,"INSERT INTO clients VALUES ('$login', '$mdp', '$mail', '$adresse')");
	echo(str_replace('%php%', "Compte créé!", file_get_contents('main.html')));
}
mysqli_close($link);

?>