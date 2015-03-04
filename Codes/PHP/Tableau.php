<?php

require 'connect.php'; // Inclusion du fichier pour la connexion à la base

/* Fonction qui crée et affiche le tableau
   - $limit le nombre de donneés que le tableau doit afficher */
function afficher_tableau($limit)
{
    $db = $GLOBALS['db'];
?>
    <table>
        <!-- En-tête du tableau -->
        <thead>
            <tr>
                <td>Date et Heure</td>
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
        $temps = preg_replace('#(\d{4})-(\d{2})-(\d{2}) (\d{2}:\d{2}:\d{2})#', 'Le $3/$2/$1 à $4', $data['temps']); // Conversion du temps

        /* Affichage des donneés : création d'une ligne */
        echo '<tr>';
            echo '<td>'.$temps.'</td>';
            echo '<td>'.$data['temperature'].'</td>';
            echo '<td>'.$data['pression'].'</td>';
        echo '</tr>';
    }   
?>
        </tbody>
    </table>
<?php
}
