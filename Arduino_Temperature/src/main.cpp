#include <Arduino.h>
#include "temperatureSensor.hpp"

TemperatureSensor temperatureSensor;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    Serial.println("Arduino Uno");
}

void loop() {
    // put your main code here, to run repeatedly:
    float h = temperatureSensor.measureHumidity();
    Serial.println("Humidite: " + String(h) + "%");

    float t = temperatureSensor.measureTemperature(false);
    Serial.println("Temperature: " + String(t) + "°C");
    t = temperatureSensor.measureTemperature(true);
    Serial.println("Temperature: " + String(t) + "°F");


    float hi = temperatureSensor.measureHeatIndex(false);
    Serial.println("Indice de temperature: " + String(hi) + "°F");
    hi = temperatureSensor.measureHeatIndex(true);
    Serial.println("Indice de temperature: " + String(hi) + "°F");

    delay(10000);
}
