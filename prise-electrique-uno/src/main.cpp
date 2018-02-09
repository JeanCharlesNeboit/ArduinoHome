#include <Arduino.h>

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


int in1 = 4;
char text[32] = "";

RF24 radio(7, 8); //CE, CSN
const uint64_t address = 0xE8E8F0F0E1LL;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

  pinMode(in1, OUTPUT);
  digitalWrite(in1, HIGH);
}

void loop() {
  if (radio.available()) {
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
  if (strcmp(text, "ON")) {
    digitalWrite(in1, HIGH);
  }
  else{
    if (strcmp(text, "OFF")) {
      digitalWrite(in1, LOW);
    }
  }
}
