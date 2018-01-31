#include <Arduino.h>
#include "temperatureSensor.h"

TemperatureSensor temperatureSensor;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    Serial.println("Arduino Uno");
}

void loop() {
    // put your main code here, to run repeatedly:
    delay(1000);
    temperatureSensor.measureHumidity();
    temperatureSensor.measureTemperature(false);
    temperatureSensor.measureTemperature(true);
    temperatureSensor.measureHeatIndex(false);
    temperatureSensor.measureHeatIndex(true);
    Serial.println();
}
