#include "temperatureSensor.h"

#define DHTPIN 8 // broche ou l'on a branche le capteur
// de-commenter le capteur utilise
//#define DHTTYPE DHT11 // DHT 11
#define DHTTYPE DHT22 // DHT 22 (AM2302)
//#define DHTTYPE DHT21 // DHT 21 (AM2301)

TemperatureSensor::TemperatureSensor(): Sensor(), DHT(DHTPIN, DHTTYPE) {
  begin();
}

TemperatureSensor::~TemperatureSensor() {

}

float TemperatureSensor::measureTemperature(bool isFahrenheit) {
  // Les valeurs lues peuvent etre vieilles de jusqu'a 2 secondes (le capteur est lent)
  float t = readTemperature(isFahrenheit);

  //On verifie si la lecture a echoue, si oui on quitte la boucle pour recommencer.
  if (isnan(t))
  {
    Serial.println("Failed to read Temperature from DHT sensor!");
    return -1;
  }

  Serial.print("Temperature: ");
  Serial.print(t);

  if (isFahrenheit == false) {
    Serial.println(" °C");
  }
  else {
    Serial.println(" °F");
  }
}

float TemperatureSensor::measureHumidity() {
  // Les valeurs lues peuvent etre vieilles de jusqu'a 2 secondes (le capteur est lent)
  float h = readHumidity();//on lit l'hygrometrie

  //On verifie si la lecture a echoue, si oui on quitte la boucle pour recommencer.
  if (isnan(h))
  {
    Serial.println("Failed to read Humidity from DHT sensor!");
    return -1;
  }

  //Affichages :
  Serial.print("Humidite: ");
  Serial.print(h);
  Serial.println(" %");
}

float TemperatureSensor::measureHeatIndex(bool isFahrenheit) {
  float t = readTemperature(isFahrenheit);
  float h = readHumidity();

  // On verifie si les lectures ont echoue.
  if (t == -1 || h == -1) {
    Serial.println("Failed to read HeatIndex from DHT sensor!");
    return -1;
  }

  // Calcul de l'indice de temperature en Celsius
  float hic = computeHeatIndex(t, h, false);
  Serial.print("Indice de temperature: ");
  Serial.print(hic);

  if (isFahrenheit == false) {
    Serial.println(" °C");
  }
  else {
    Serial.println(" °F");
  }
}

/*
// La lecture du capteur prend 250ms
// Les valeurs lues peuvent etre vieilles de jusqu'a 2 secondes (le capteur est lent)
float h = readHumidity();//on lit l'hygrometrie
float t = readTemperature();//on lit la temperature en celsius (par defaut)
// pour lire en farenheit, il faut le paramère (isFahrenheit = true) :
float f = readTemperature(true);

//On verifie si la lecture a echoue, si oui on quitte la boucle pour recommencer.
if (isnan(h) || isnan(t) || isnan(f))
{
  Serial.println("Failed to read from DHT sensor!");
  return;
}

// Calcul de l'indice de temperature en Farenheit
float hif = computeHeatIndex(f, h);
// Calcul de l'indice de temperature en Celsius
float hic = computeHeatIndex(t, h, false);

//Affichages :
Serial.print("Humidite: ");
Serial.print(h);
Serial.print(" %\t");
Serial.print("Temperature: ");
Serial.print(t);
Serial.print(" *C ");
Serial.print(f);
Serial.print(" *F\t");
Serial.print("Indice de temperature: ");
Serial.print(hic);
Serial.print(" *C ");
Serial.print(hif);
Serial.println(" *F");*/
