// ...
float moyenneTemperature(0);

for (int i(0) ; i < 10 ; i++)
{
  moyenneTemperature += capteur.bmp085GetTemperature(capteur.bmp085ReadUT());
  delay(90000);
}

moyenneTemperature /= NB_RELEVES;
// ...
