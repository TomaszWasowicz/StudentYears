#ifndef SAMOCHOD_HPP
#define SAMOCHOD_HPP
#include <Pojazd.h>

class SAMOCHOD: public Pojazd
{
    public:

        SAMOCHOD();
        virtual ~SAMOCHOD();

        bool getDrivingWheel();
        void setDrivingWheel(bool value);

        bool getCarRadio();
        void setCarRadio(bool value);

        bool getSeats();
        void setSeats(bool value);

    protected:

    private:

        bool DrivingWheel;
        bool CarRadio;
        bool Seats;

};

#endif // SAMOCHOD_HPP
