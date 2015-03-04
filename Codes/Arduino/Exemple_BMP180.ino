#include <Barometer.h> // On inclut la bibliothéque du constructeur.
#include <Wire.h>

float temperature(0), pression(0); // On déclare les variables.

Barometer capteur; // On déclare le capteur.

void setup()
{
  Serial.begin(9600); // On initialise le communication série
  capteur.init();     // et le capteur.
}

void loop()
{
  /* On stocke la température et la pression. */
  temperature = capteur.bmp085GetTemperature(capteur.bmp085ReadUT());
  pression = capteur.bmp085GetPressure(capteur.bmp085ReadUP());

  /* On affiche les données. */
  Serial.print("Température : ");
  Serial.print(temperature);
  Serial.println(" °C");
  Serial.print("Pression : ");
  Serial.print(pression);
  Serial.println(" Pa");
  Serial.println();

  delay(1000);
}
