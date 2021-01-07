#include "Pojazd.h"
#include <iostream>

int Pojazd::counter = 0;

Pojazd::Pojazd()
{
    Pojazd::counter ++;

    //Init of the fields
    wheelNumber = 0;    //ex: boat
    Engine = false;   //ex: sailboat

    std::cout << "Konstruktor Pojazd : " << std::hex << "0x" <<(int)this->getMemAddr() << std::endl;
}

Pojazd::~Pojazd()
{
    std::cout << "Destruktor Pojazd : " << std::hex << "0x" <<(int)this->getMemAddr() << std::endl;
    Pojazd::counter --;
}

void* Pojazd::getMemAddr()
{
    return (void *)this;
}

int Pojazd::getCounter()
{
    return Pojazd::counter;
}

int Pojazd::getWheelNumber()
{
    return wheelNumber;
}

void Pojazd::setWheelNumber(int value)
{
    wheelNumber = value;
}

int Pojazd::getEngine()
{
    return Engine;
}

void Pojazd::setEngine(int value)
{
    Engine = value;
}

bool Pojazd::getSailNumber()
{
    return SailNumber;
}

void Pojazd::setSailNumber(bool value)
{
    SailNumber = value;
}
