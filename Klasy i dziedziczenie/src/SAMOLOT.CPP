#include "Samolot.h"
#include <Pojazd.h>
#include <iostream>

Samolot::Samolot()
{
    std::cout << "Konstruktor Samolot : " << std::hex << "0x" <<(int)this->getMemAddr() << std::endl;
}

Samolot::~Samolot()
{
    std::cout << "Destruktor Samolot : " << std::hex << "0x" <<(int)this->getMemAddr() << std::endl;
}

int Samolot::getWingsNumber()
{
    return WingsNumber;
}

bool Samolot::setWingsNumber(int value)
{
    WingsNumber = value;
}

int Samolot::getWindowsNumber()
{
    return WindowsNumber;
}

bool Samolot::setWindowsNumber(int value)
{
    WindowsNumber = value;
}

bool Samolot::getPropeller()
{
    return Propeller;
}

void Samolot::setPropeller(bool value)
{
    Propeller = value;
}

