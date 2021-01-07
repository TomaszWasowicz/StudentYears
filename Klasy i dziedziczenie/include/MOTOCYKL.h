#ifndef MOTOCYKL_H
#define MOTOCYKL_H
#include <Pojazd.h>

class MOTOCYKL : public Pojazd
{
    public:

        MOTOCYKL();
        virtual ~MOTOCYKL();

        int getBasketNumber();
        void setBasketNumber(int value);

        int getTrumpet();
        void setTrumpet(int value);

        bool getExchaustPipe();
        void setExchaustPipe(bool value);

    protected:

    private:

        int BasketNumber;
        int Trumpet;
        bool ExchaustPipe;
};

#endif // MOTOCYKL_H
