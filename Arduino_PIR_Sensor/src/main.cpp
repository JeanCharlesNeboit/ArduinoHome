#include <Arduino.h>

#define IR_output 2

void detection_IR(){
  if(digitalRead(IR_output)==HIGH){  //si le signal est à l'état haut
   Serial.println("mouvement detecte");
  }
  if(digitalRead(IR_output)==LOW){ //si le signal est à l'état bas
   Serial.println("pas de mouvement detecte");
  }
}

void setup() {
  pinMode(IR_output,INPUT);
  attachInterrupt(digitalPinToInterrupt(IR_output),detection_IR,CHANGE); //détecte un changement d'état
  Serial.begin(9600);
}

void loop() {

}
