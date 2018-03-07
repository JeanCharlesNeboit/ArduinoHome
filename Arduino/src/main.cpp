#include <Arduino.h>

/* Unidirectionnel Transmitter

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

void setup() {
    // put your setup code here, to run once:

    // Transmitter
    radio.begin();
    radio.openWritingPipe(address);
    radio.setPALevel(RF24_PA_MIN);
    radio.stopListening();
}

void loop() {
    // put your main code here, to run repeatedly:

    // Transmitter
    const char text[] = "Hello World";
    radio.write(&text, sizeof(text));
    delay(1000);
}
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//#define led 12

RF24 radio(7, 8); // CE, CSN
const byte addresses[][6] = {"00001", "00002"};
//boolean buttonState = 0;
char text[32] = "";
int i = 0;

void setup() {
  Serial.begin(9600);
  //pinMode(12, OUTPUT);
  radio.begin();
  radio.openWritingPipe(addresses[1]); // 00001
  radio.openReadingPipe(1, addresses[0]); // 00002
  radio.setPALevel(RF24_PA_MIN);
}

void loop() {
  if (i == 0) {
    delay(5);
    radio.stopListening();
    //int potValue = analogRead(A0);
    int angleValue = 1;
    radio.write(&angleValue, sizeof(angleValue));
    delay(5);
    radio.startListening();
    while (!radio.available());
    radio.read(&text, sizeof(text));
    //if (buttonState == HIGH) {
      //digitalWrite(led, HIGH);
      //Serial.println("HIGHT");
      Serial.println(text);
    /*}
    else {
      //digitalWrite(led, LOW);
      Serial.println("LOW");
    }*/
    i = i + 1;
  }
}
