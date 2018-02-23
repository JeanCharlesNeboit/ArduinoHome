#include <Arduino.h>
#include "temperatureSensor.hpp"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

TemperatureSensor temperatureSensor;

RF24 radio(7, 8); //CE, CSN
const uint64_t addressRead = 0xE8E8F0F0E1LL;
const uint64_t addressWrite = 0xE8E8F0F0E2LL;
char buffer[200] = "";

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    Serial.println("Arduino Uno");
    radio.begin();
    radio.openWritingPipe(addressWrite);
    radio.openReadingPipe(1, addressRead);
    radio.setPALevel(RF24_PA_MAX);
    radio.stopListening();
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
    Serial.println("Indice de temperature: " + String(hi) + "°C");

    String s = String(hi, 2);
    radio.write(s.c_str(), sizeof(s.c_str())+3*sizeof(char));

    hi = temperatureSensor.measureHeatIndex(true);
    Serial.println("Indice de temperature: " + String(hi) + "°F");

    delay(10000);
}
