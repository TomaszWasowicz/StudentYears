#include "MOTOROWKA.h"
#include <iostream>

MOTOROWKA::MOTOROWKA()
{
    std::cout << "Konstruktor Motorowka : " << std::hex << "0x" <<(int)this->getMemAddr() << std::endl;
}

MOTOROWKA::~MOTOROWKA()
{
    std::cout << "Destruktor Motorowka : " << std::hex << "0x" <<(int)this->getMemAddr() << std::endl;
}
int MOTOROWKA::getNumberOfSeats(){
    return NumberOfSeats;
}
void MOTOROWKA::setNumberOfSeats(int wartoscS){
        NumberOfSeats = wartoscS;
}
bool MOTOROWKA::getCaptain(){
    return IsCaptain;
}
bool MOTOROWKA::setCaptain(bool wartoscC){
        IsCaptain = wartoscC;
}
bool MOTOROWKA::getSwimming(){
    return IsSwimming;
}
bool MOTOROWKA::setSwimming(bool wartoscW){
        IsSwimming =  wartoscW;
}
