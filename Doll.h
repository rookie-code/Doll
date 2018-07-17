#ifndef Doll_h
#define Doll_h
#include<arduino.h>
using namespace std;

class Doll{
    private:
        String actionName;     // il nome della funzione del motore es aziona bocca
        int status;            // la posizione in cui è
        int zero;              // la posizione iniziale 
        int maxPosition;       // max value of resistorPosition
        int minPosition;       // min value of resistorPosition
        byte pinDirection;
        byte pinPower;
        byte pinResistor;
        int speed;             // velocità
        int positions[10]; 
        
       


    public:
        Doll(byte _pinDirection, byte  _pinPower, byte _pinResistor); // constructor
        void addPosition(int position, int resistorPosition);            // es. "sorriso" 20 
        void effect();                                                          // effetti da aggiungere dalla posizione di riferimento es. vibro etc.
        void moveToPosition(int position, int speed);                              // indicando la il nome della posizione il motore si muove per raggiungerla
        void start(int _zero, int _minPosition, int _maxPosition);                                                        // fa lo zero e attiva tutti i vari pin digitali e analogici
        void setPin();
        int getPosition();                                                     //ritorna il valore della resistenza che indica la posizione
        int targetPosition(int position);                                //ritorna il valore della posizione in base al suo nome
        void moveUp(int speed);
        void moveDown(int speed);
        void moveStop();
    
        
             
};




#endif