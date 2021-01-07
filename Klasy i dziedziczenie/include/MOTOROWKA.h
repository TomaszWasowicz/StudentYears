#ifndef MOTOROWKA_H
#define MOTOROWKA_H

#include <Pojazd.h>

class MOTOROWKA : public Pojazd
{
    public:
        MOTOROWKA();
        virtual ~MOTOROWKA();

        int getNumberOfSeats();
        void setNumberOfSeats(int wartoscS);

        bool setCaptain(bool wartoscC);
        bool getCaptain();

        bool setSwimming(bool wartoscW);
        bool getSwimming();


    protected:

    private:
        bool IsSwimming;
        bool IsCaptain;
        int NumberOfSeats;
};

#endif // MOTOROWKA_H
