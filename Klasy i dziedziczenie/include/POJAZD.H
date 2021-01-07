#ifndef POJAZD_H
#define POJAZD_H

#include <string>

class Pojazd
{
    public:

        Pojazd();                  //Constructor
        virtual ~Pojazd();         //Destructor
        static int getCounter();   //Number of created objects

        int getWheelNumber();
        void setWheelNumber(int value);

        int getEngine();
        void setEngine(int value);

        bool getSailNumber();
        void setSailNumber(bool value);


    protected:
        void* getMemAddr();

    private:
        static int counter;
        int wheelNumber;            //Number of wheels: car 4, boat 0
        int Engine;                 //How many engines?
        bool SailNumber;            //Does the object have a sail ?

};
#endif // POJAZD_H
