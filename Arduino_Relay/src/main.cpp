#include <Arduino.h>

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


int in1 = 4;
char text[32] = "";
char ack[10] = "";

RF24 radio(7, 8); //CE, CSN
const uint64_t addressRead = 0xE8E8F0F0E1LL;
const uint64_t addressWrite = 0xE8E8F0F0E2LL;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(addressWrite);
  radio.openReadingPipe(1, addressRead);
  radio.setPALevel(RF24_PA_MAX);

  pinMode(in1, OUTPUT);
  digitalWrite(in1, HIGH);
}

void loop() {
  radio.startListening();
  if (radio.available()) {
    //while (radio.available()) {
      radio.read(&text, sizeof(text));
      Serial.println(text);
    //}
    //delay(10);
    radio.stopListening();
    radio.write("ACK", sizeof("ACK"));
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
