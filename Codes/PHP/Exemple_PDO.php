<?php

/* On essaie de se connecter à la base. */
try
{
	/* Connexion
	   - tpe : nom de la base
	   - localhost : serveur (ici, en local)
	   - root : utilisateur
	   - root : mot de passe */
	$bdd = new PDO("mysql:dbname=tpe;host=localhost", "root", "root", array(PDO::ATTR_ERRMODE => PDO::ERRMODE_WARNING));
}
catch(PDOException $e)
{
	die("Impossible de se connecter à MySQL : ".$e->getMessage()); // Sinon, on affiche un message d'erreur
}

$requete = $bdd->query("SELECT * FROM `datalog_meteo` ORDER BY id DESC LIMIT 5"); // On lance une requête sur la table datalog_meteo : les 5 derniers enregistrements.
$donnees = $requete->fetchAll(PDO::FETCH_ASSOC); // Génération du tableau contenant les données

foreach($donnees as $donnee) // Parcours des données ($donnees : tous le résultat de la requête ; $donnee : un enregistrement)
{
	$temps = preg_replace("#(\d{4})-(\d{2})-(\d{2}) (\d{2}:\d{2}:\d{2})#", "$3/$2/$1 à $4", $donnee["temps"]); // Conversion du temps

	/* Affichage des donneés */
	echo $temps." ; ".$donnee["temperature"]." °C ; ".$donnee["pression"]." hPa\r\n"; // \r\n : saut de ligne
}
