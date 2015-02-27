/* Inclusion des bibliothèques */
#include <Wire.h>
#include <SPI.h>
#include <Barometer.h>
#include <EthernetV2_0.h>

#define DEBUG true // Pour déboguer

#define W5200_CS 10
#define SDCARD_CS 4

#define NB_RELEVES 10 // Nombre de relevés par passage
#define INTERVALLE 1.5 * 1000 // Intervalle entre les envois de données
#define TEMPS INTERVALLE / NB_RELEVES // Temps entre chaque relevé

Barometer capteur; // Déclaration du capteur

byte MAC[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress IP(192, 168, 1, 3); // Adresse IP de l'Arduino
IPAddress DNS(192, 168, 1, 1);

EthernetClient client; // Déclaration du client Ethernet

char serveur[] = "192.168.1.2"; // Adresse IP du serveur

unsigned long tempsDerniereConnexion;
boolean dernierConnecte(false);

void setup()
{
  capteur.init(); // Initialisation du BMP180

  /* Désactivation de la carte SD */
  pinMode(SDCARD_CS, OUTPUT);
  digitalWrite(SDCARD_CS, HIGH);

  delay(1000);

  Ethernet.begin(MAC, IP); // Démarrage de la connexion Ethernet

  if (DEBUG)
  {
    Serial.begin(9600); // Démarrage de la liaison série
    Serial.print("Mon adresse IP : ");
    Serial.println(Ethernet.localIP());
  }
}

void loop()
{
  /* Affichage des résultats des requêtes */
  if (DEBUG)
  {
    while (client.available())
    {
      char c(client.read());
      Serial.print(c);
    }
  }
  
  if (!client.connected() && dernierConnecte)
  {
    Serial.println("Déconnexion.");

    client.stop();
  }

  /* moyennes : tableau de 2 cases
    - 1re : moyenne de la température
    - 2de : moyenne de la pression */
  float moyennes[2] = {};

  /* Relevés des données */
  for (int i(0) ; i < NB_RELEVES ; i++) // On fait la somme de 10 relevés de température et de pression.
  {
    moyennes[0] += capteur.bmp085GetTemperature(capteur.bmp085ReadUT()); // Température
    moyennes[1] += capteur.bmp085GetPressure(capteur.bmp085ReadUP()); // Pression

    delay(TEMPS);
  }

  moyennes[0] = moyennes[0] / NB_RELEVES;
  moyennes[1] = moyennes[1] / NB_RELEVES / 100; // Division par 100 pour convertir les Pa en hPa

  /* Affichage des valeurs */
  if (DEBUG)
  {
    Serial.print("Moyennes : ");
    Serial.print(moyennes[0]);
    Serial.print(" °C et ");
    Serial.print(moyennes[1]);
    Serial.println(" hPa");
  }

  if (!client.connected() && (millis() - tempsDerniereConnexion > INTERVALLE))
  {
    if (client.connect(serveur, 80)) // Connexion au port 80
    {
      if (DEBUG)
        Serial.println("Connexion.");

      /* Envoi de la requête */
      client.print("GET /arduino.php?pass=123&temperature=");
      client.print(moyennes[0]);
      client.print("&pression=");
      client.print(moyennes[1]);
      client.println(" HTTP/1.1");
      client.println("Host: 192.168.1.2");
      client.println("User-Agent: Arduino Ethernet");
      client.println("Connection: close");
      client.println();

      tempsDerniereConnexion = millis();
    }
    else
    {
      if (DEBUG)
      {
        Serial.println("Erreur de connexion.");
        Serial.println("Déconnexion.");
      }

      client.stop();
    }
  }

  dernierConnecte = client.connected();
}
