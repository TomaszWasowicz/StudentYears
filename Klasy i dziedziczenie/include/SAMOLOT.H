#ifndef SAMOLOT_H
#define SAMOLOT_H
#include <Pojazd.h>


class Samolot : public Pojazd
{
    public:

        Samolot();
        virtual ~Samolot();

        int getWingsNumber();
        bool setWingsNumber(int value);

        int getWindowsNumber();
        bool setWindowsNumber(int value);

        bool getPropeller();
        void setPropeller(bool value);

    protected:

    private:

        int WingsNumber;
        int WindowsNumber;
        bool Propeller;

};

#endif // SAMOLOT_H
