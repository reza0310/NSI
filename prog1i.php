<?php
$sqlHost='localhost';
$sqlUser='root';
$sqlPass='root';

$link = mysqli_connect($sqlHost,$sqlUser,$sqlPass, "geographie") or die ('Erreur '.mysqli_connect_error());
mysqli_set_charset ($link,"utf8");

$reponses=array(mysqli_query($link ,"SELECT * FROM departements"), mysqli_query($link ,"SELECT sum(population_2010) FROM communes"), mysqli_query($link ,"SELECT count(*) FROM communes WHERE num_departement = 44 "), mysqli_query($link ,"SELECT * FROM communes ORDER BY surface ASC LIMIT 10"), mysqli_query($link ,"SELECT * FROM communes ORDER BY population_2010 DESC LIMIT 10"), mysqli_query($link ,"SELECT * FROM communes WHERE num_departement = 44 ORDER BY population_2010/surface DESC LIMIT 12"), mysqli_query($link ,"SELECT num_departement AS \"Numéro de département\", count(*) AS \"Nombre de communes\" FROM communes GROUP BY num_departement"));
//list($reponse1, $reponse2, $reponse3, $reponse4, $reponse5, $reponse6, $reponse7) = $reponses;
$i = 0;
while ($i < 7) 
	{
		echo ("<br></br>Requête $i:<br>");
		while ($res=mysqli_fetch_array($reponses[$i]))
			{
				if ($i == 0) {
					$numdep=$res[0];
					$nom=$res[2];
					echo imap_utf8 ("Le numéro du département $nom est $numdep <br>");
				}
				else if ($i == 1) {
					echo ("Il y a $res[0] personnes vivant en France en 2010<br>");
				}
				else if ($i == 2) {
					echo ("Il y a $res[0] communes en Loire-Atlantique<br>");
				}
				else if ($i == 3) {
					$numdep=$res[0];
					$nom=$res[1];
					echo imap_utf8 ("La ville de $nom dans le $numdep fait partie des 10 plus petites de France <br>");
				}
				else if ($i == 4) {
					$numdep=$res[0];
					$nom=$res[1];
					echo imap_utf8 ("La ville de $nom dans le $numdep fait partie des 10 plus peuplées de France <br>");
				}
				else if ($i == 5) {
					$numdep=$res[0];
					$nom=$res[1];
					echo imap_utf8 ("La ville de $nom dans le $numdep fait partie des 12 plus densément peuplées de Loire-Atlantique <br>");
				}
				else if ($i == 6) {
					$numdep=$res[0];
					$nom=$res[1];
					echo imap_utf8 ("Le département numéro $numdep contient $nom communes.<br>");
				}
			}
		$i = $i+1;
	}
	
mysqli_close($link);

?>
