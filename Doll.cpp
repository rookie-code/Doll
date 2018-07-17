#include <Doll.h>
#include <arduino.h>

Doll::Doll(byte _pinDirection, byte  _pinPower, byte _pinResistor){
    pinDirection = _pinDirection;
    pinPower = _pinPower;
    pinResistor = _pinResistor;
    setPin();

}


void Doll::addPosition(String namePosition, int resistorPosition){
    
    for(int x = 0; x <= 10; x++){
        if(!positions[x].namePosition){
            positions[x].namePosition = namePosition;
            positions[x].namePosition = resistorPosition;
            break;
        }
        
    }
};          


void Doll::effect(){};   


void Doll::moveToPosition(String namePosition, int speed){
    int targetP = targetPosition(namePosition);
    actualPosition = getPosition();
    
    if(targetP >= actualPosition){
        moveDown(255);
        while(actualPosition <= targetP){
            actualPosition = getPosition();
        }
        moveStop();
    };
    if(targetP <= actualPosition){
        moveUp(255);
        while(actualPosition >= targetP){
            actualPosition = getPosition();
        }
        moveStop();
    };
    
};

// enable pin for motor
void Doll::setPin(){
    
    
    pinMode(pinDirection, OUTPUT);
    pinMode(pinPower, OUTPUT);
    pinMode(pinResistor, OUTPUT);
};

// set the property rage of motor escursion and zero position
void Doll::start(int _zero, int _minPosition, int _maxPosition){
    zero = _zero;
    minPosition = _minPosition;
    maxPosition = _maxPosition;
    addPosition("zero", zero);

};          


int Doll::getPosition(){
    return analogRead(pinResistor);
};          


int Doll::targetPosition(String _namePosition){
    for(int i = 0; i = 10; i++){
        if(positions[i].namePosition == _namePosition){
            return positions[i].resistorPosition;
        }
    }
};


void Doll::moveUp(int speed){
    digitalWrite(pinDirection, HIGH);
    analogWrite(pinPower, speed);
    delay(200);
    moveStop();
};


void Doll::moveDown(int speed){
    digitalWrite(pinDirection, LOW);
    analogWrite(pinPower, speed); 
    delay(200);
    moveStop();   
};

void Doll::moveStop(){
    analogWrite(pinPower, 0); 
};
         