#include <DollMotor.h>
#include <arduino.h>


DollMotor::DollMotor(byte _pinDirection, byte  _pinPower, byte _pinResistor){
    pinDirection = _pinDirection;
    pinPower = _pinPower;
    pinResistor = _pinResistor;
    setPin();

}


void DollMotor::addPosition(int position, int resistorPosition){
    positions[position]= resistorPosition;
};          


void DollMotor::effect(){};   


void DollMotor::moveToPosition(int position, int _speed){
    int targetP = targetPosition(position);
    int actualPosition = getPosition();
    Serial.println(String(targetP));
    if(targetP >= actualPosition){
        moveDown(_speed);
        while(actualPosition <= targetP){
            actualPosition = getPosition();
            Serial.println(String(actualPosition));
        }
        moveStop();
    };
    if(targetP <= actualPosition){
        moveUp(_speed);
        while(actualPosition >= targetP){
            actualPosition = getPosition();
            Serial.println(String(actualPosition));
        }
        moveStop();
    };
    
};

// enable pin for motor
void DollMotor::setPin(){
    
    
    pinMode(pinDirection, OUTPUT);
    pinMode(pinPower, OUTPUT);
    pinMode(pinResistor, OUTPUT);
};

// set the property rage of motor escursion and zero position
void DollMotor::start(int _zero, int _minPosition, int _maxPosition){
    zero = _zero;
    minPosition = _minPosition;
    maxPosition = _maxPosition;
    addPosition(1, zero);
    Serial.println("move to position");
    moveToPosition(1, 100);

};          


int DollMotor::getPosition(){
    int resistor = analogRead(pinResistor);
    return map(resistor,0, 1023, minPosition, maxPosition);
};          


int DollMotor::targetPosition(int position){
    Serial.println("targetPosition");
    Serial.println(String(positions[position]));
    return positions[position];
};


void DollMotor::moveUp(int speed){
    digitalWrite(pinDirection, HIGH);
    analogWrite(pinPower, speed);
    
    
};


void DollMotor::moveDown(int speed){
    digitalWrite(pinDirection, LOW);
    analogWrite(pinPower, speed); 
     
};

void DollMotor::moveStop(){
    analogWrite(pinPower, 0); 
};
         