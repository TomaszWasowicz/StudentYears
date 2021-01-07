#include <iostream>
#include <string>
#include <Pojazd.h>
#include <SAMOLOT.H>
#include <MOTOCYKL.h>
#include <SAMOCHOD.H>

using namespace std;

int main()
{
    cout << sizeof(int) << endl;
    cout << sizeof(void*) << endl;

    cout << "Programowanie obiektowe" << endl;

    cout << "Liczba obiektow: " << Pojazd::getCounter() << endl;

    Pojazd obiekt1;
    Pojazd obiekt2;
    Pojazd obiekt3;
    obiekt1.setEngine(1);
    obiekt2.setWheelNumber(2);
    obiekt3.setSailNumber(0);

    cout << "Liczba obiektow: " << Pojazd::getCounter() << endl;

    MOTOCYKL motocykl1;
    MOTOCYKL motocykl2;
    motocykl2.setEngine(1);
    motocykl1.setBasketNumber(2);
    motocykl1.getTrumpet();
    motocykl2.setExchaustPipe(1);

    cout << "Liczba obiektow: " << Pojazd::getCounter() << endl;

    Samolot samolot1;
    Samolot samolot2;
    samolot1.setEngine(1);
    samolot1.setWheelNumber(8);
    samolot1.setWingsNumber(2);
    samolot2.getPropeller();
    samolot2.setWindowsNumber(10);

    cout << "Liczba obiektow: " << Pojazd::getCounter() << endl;

    SAMOCHOD samochod1;
    SAMOCHOD samochod2;
    samochod1.setWheelNumber(4);
    samochod1.getDrivingWheel();
    samochod2.setCarRadio(1);

    cout << "Liczba obiektow: " << Pojazd::getCounter() << endl;

    return 0;
}
