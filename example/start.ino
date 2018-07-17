#include "Doll.h"

const byte _pinDirection = 3;
const byte _pinPower = 11;
const byte _pinResistor = A0;
int valueResistor;


Doll* doll = new Doll(_pinDirection, _pinPower, _pinResistor);

void setup() {
    Serial.begin(9600);
    doll->start(50, 0, 130);
   
    
}
 
 
void loop() {
  
}