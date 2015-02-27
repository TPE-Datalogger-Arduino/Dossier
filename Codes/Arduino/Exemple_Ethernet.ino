#include <SPI.h>
#include <EthernetV2_0.h> // On inclus la bibliothèque.

#define W5200_CS 10
#define SDCARD_CS 4

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED}; // On déterminer l'adresse MAC de l'Arduino.

char serveur[] = "google.fr"; // Serveur vers lequel on va faire la requête.

EthernetClient client; // On crée un client Ethernet.

void setup()
{
  Serial.begin(9600);

  /* Désactivation de la carte SD */
  pinMode(SDCARD_CS,OUTPUT);
  digitalWrite(SDCARD_CS,HIGH);

  /* On commence la connexion Ethernet. */
  if (Ethernet.begin(mac) == 0)
  {
    Serial.println("Impossible de configuer la connexion Ethernet.");

    while (true); // On arrête alors le programme.
  }

  delay(1000);

  Serial.println("Connexion.");

  /* On se connecte au port 80 du serveur. */
  if (client.connect(server, 80))
  {
    Serial.println("Connecté.");
    
    client.println("GET / HTTP/1.0"); // On lance une requête HTTP.
    client.println();
  } 
  else
  {
    Serial.println("Erreur de connexion.");
  }
}

void loop()
{
  /* On affiche le résultat de la requête s'il existe. */
  if (client.available())
  {
    char c = client.read();
    Serial.print(c);
  }

  /* Quand le client n'est pas connecté, on arrête le client. */
  if (!client.connected())
  {
    Serial.println("Déconnexion.");
    client.stop();

    while (true);
  }
}

