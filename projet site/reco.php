<?php
$sqlHost='localhost';
$sqlUser='root';
$sqlPass='root';

$link = mysqli_connect($sqlHost,$sqlUser,$sqlPass, "commerce") or die ('Erreur '.mysqli_connect_error());
mysqli_set_charset ($link,"utf8");

$login = $_POST['login'];
$rep = mysqli_query($link ,"SELECT * FROM articles WHERE NOT quantite = 0");
$srt = "";
while ($arr=mysqli_fetch_array($rep)) {
	$srt .= "<div class='article'>$arr[1]<input class=\"chiffres\" type=\"number\" name='$arr[0]' min=\"0\" max='$arr[2]' value=0><p id=\"prix\">$arr[4]€</p><p id=\"quantite\">Reste: $arr[2]</p></div>";
}
echo(str_replace('%php%', "<form action='commander.php' method='post'><input type='hidden' name='login' value='$login'>".$srt."<input type='submit' class='bouton' id='commander' value='Passer la commande'></form>", str_replace('%cache%', "<input type='hidden' name='login' value='$login'>", file_get_contents('main_alternatif.html'))));
mysqli_close($link);
?>