<?php 
/*

         Sistema de Busqueda de Canciones usando solo so nombre Code by TioJhon free Share
		
		Con este sencillo script podras facilmente buscar canciones por su nombre y se reproduciran en tu Servidor

*/
$name = (isset($_GET['n'])) ? urlencode($_GET['n']) : exit("Escribe un Nombre");
$url = "https://api.yourdomain.com.sa/sounds/?s=".$name;
$content = file_get_contents($url);
$first_step = explode( '<audio controls preload="none">' , $content );
$links = array();
foreach ($first_step as $key => $value) {
	if($key > 0)
	{
		$second_step = explode("</audio>" , $value );
		if (preg_match('/"([^"]+)"/', $second_step[0], $m)) {
			array_push($links, $m[1]);  
			break;
		} else {
		}
	}
}
header("Location: ".$links[0]);
?>
