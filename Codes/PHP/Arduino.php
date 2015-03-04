<?php

require 'sql.php'; // Inclusion du fichier contenant les commandes pour accéder à la base

$data = array(); // Création d'un tableau contenant les données

if (isset($_GET['pass']) && $_GET['pass'] == '123') // On test si le mot de passe est bon.
{
    $data['temps'] = 'NOW()'; // Le temps est maintenant.
    /* Si il y a une température donnée, alors on la convertit. Sinon, rien. */
    $data['temperature'] = (isset($_GET['temperature'])) ?
                                htmlspecialchars($_GET['temperature']) : NULL;
    /* Idem pour la pression */
    $data['pression'] = (isset($_GET['pression'])) ?
                                htmlspecialchars($_GET['pression']) : NULL;

    insert($data); // Et on insert les données dans la base.
}
