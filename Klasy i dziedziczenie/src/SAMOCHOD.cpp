#include "SAMOCHOD.H"
#include <Pojazd.h>
#include <iostream>

SAMOCHOD::SAMOCHOD()
{
    std::cout << "Konstruktor Samochod : " << std::hex << "0x" <<(int)this->getMemAddr() << std::endl;
}

SAMOCHOD::~SAMOCHOD()
{
    std::cout << "Destruktor Samochod : " << std::hex << "0x" <<(int)this->getMemAddr() << std::endl;
}

bool SAMOCHOD::getDrivingWheel()

{
    return DrivingWheel;
}

void SAMOCHOD::setDrivingWheel(bool value)

{
    DrivingWheel =  value;
}

bool SAMOCHOD::getCarRadio()

{
    return CarRadio;
}

void SAMOCHOD::setCarRadio(bool value)

{
    CarRadio = value;
}

bool SAMOCHOD::getSeats()

{
    return Seats;
}

void SAMOCHOD::setSeats(bool value)

{
    Seats = value;
}
