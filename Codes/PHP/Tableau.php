<?php

require 'connect.php'; // Inclusion du fichier pour la connexion à la base

/* Fonction qui crée et affiche le tableau
   - $limit le nombre de donneés que le tableau doit afficher */
function table($limit)
{
	$db = $GLOBALS['db'];
?>
	<table>
		<thead>
			<tr>
				<td>Date et heure</td>
				<td>Température (&deg;C)</td>
				<td>Pression (hPa)</td>
			</tr>
		</thead>
		<tbody>
<?php
	$query = $db->query('SELECT temps, temperature, pression FROM `datalog_meteo` ORDER BY id DESC LIMIT '.$limit); // Requête SQL avec LIMIT
	$meteo = $query->fetchAll(PDO::FETCH_ASSOC);

	foreach($meteo as $data) // Parcours des données
	{
		$temps = preg_replace('#(\d{4})-(\d{2})-(\d{2}) (\d{2}:\d{2}:\d{2})#', '$3/$2/$1 à $4', $data['temps']); // Conversion du temps
		/* Nombre décimal avec une virgule */
		$temperature = preg_replace('/\./', ',', $data['temperature']);
		$pression = preg_replace('/\./', ',', $data['pression']);

		/* Affichage des donneés : création d'une ligne */
		echo '<tr>';
			echo '<td>'.$temps.'</td>';
			echo '<td>'.$temperature.'</td>';
			echo '<td>'.$pression.'</td>';
		echo "</tr>\r\n";
	}
?>
		</tbody>
	</table>
<?php
}
