#include "MOTOCYKL.h"
#include <iostream>
#include <Pojazd.h>

MOTOCYKL::MOTOCYKL()
{
    std::cout << "Konstruktor Motocykl : " << std::hex << "0x" <<(int)this->getMemAddr() << std::endl;
}

MOTOCYKL::~MOTOCYKL()
{
    std::cout << "Destruktor Motocykl : " << std::hex << "0x" <<(int)this->getMemAddr() << std::endl;
}

int MOTOCYKL::getBasketNumber()
{
    return BasketNumber;
}

void MOTOCYKL::setBasketNumber(int value)
{
    BasketNumber = value;
}

int MOTOCYKL::getTrumpet()
{
    return Trumpet;
}

void MOTOCYKL::setTrumpet(int value)
{
    Trumpet = value;
}

bool MOTOCYKL::getExchaustPipe()
{
    return ExchaustPipe;
}

void MOTOCYKL::setExchaustPipe(bool value)
{
    ExchaustPipe = value;
}

