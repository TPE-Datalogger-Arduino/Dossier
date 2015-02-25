#define LED 13 // On stocke l'entrée dans un constante.

/* Phase d'initialisation */
void setup()
{
  pinMode(LED, OUTPUT); // On dit que la LED est une sortie.
}

/* Boucle infinie */
void loop()
{
  digitalWrite(LED, HIGH); // On éteint la LED.
  delay(1000);             // On attend 1000 ms = 1 s.
  digitalWrite(LED, LOW);  // On allume la LED.
  delay(1000);             // On attend 1 s.
}
