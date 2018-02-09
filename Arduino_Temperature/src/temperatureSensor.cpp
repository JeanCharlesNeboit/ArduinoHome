#include "temperatureSensor.hpp"

#define DHTPIN 4
#define DHTTYPE DHT22

TemperatureSensor::TemperatureSensor(): DHT(DHTPIN, DHTTYPE) {
  begin();
}

TemperatureSensor::~TemperatureSensor() {

}

float TemperatureSensor::measureTemperature(bool isFahrenheit) {
  float t = readTemperature(isFahrenheit);
  if (isnan(t))
  {
    Serial.println("Failed to read Temperature from DHT sensor!");
    return -1;
  }
  return t;
}

float TemperatureSensor::measureHumidity() {
  float h = readHumidity();//on lit l'hygrometrie
  if (isnan(h))
  {
    Serial.println("Failed to read Humidity from DHT sensor!");
    return -1;
  }
  return h;
}

float TemperatureSensor::measureHeatIndex(bool isFahrenheit) {
  float t = readTemperature(isFahrenheit);
  float h = readHumidity();
  if (t == -1 || h == -1) {
    Serial.println("Failed to read HeatIndex from DHT sensor!");
    return -1;
  }
  float hi = computeHeatIndex(t, h, isFahrenheit);
  return hi;
}
