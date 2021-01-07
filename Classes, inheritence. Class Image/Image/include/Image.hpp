#ifndef IMAGE_HPP
#define IMAGE_HPP
#include <iostream>

typedef unsigned char byte;
using namespace std;

class Image
{
    public:

        Image(int width = 0, int height = 0);                       // construktor z 2 argumentami
        Image(Image& right);                                        //konstruktor kopiujacy
        ~Image();                                                   // destruktor
        void fillInImage(byte value = 0);                           // metoda wypelniajaca obraz jakies wartosci
        byte readPixel(int x = 0, int y = 0) const;                  // metoda pozwalajaca odczyt danego pixel, dopisek const znaczy ze metoda nie moze zmienic obiektu
        void writePixel(int x, int y, byte value);                  // metoda pozwalajaca zapisa danego pixela
        int getWidth() const;                                       // metoda odczytujace wielkosc obrazka
        int getHeight() const;

        Image& operator=(const Image& right);                       // metoda przeciazajaca operator =
        byte& operator()(int x, int y);                             // metoda przeciazajaca operator ()
        byte operator()(int x, int y) const;                        // metoda przeciazajaca operator ()
        friend ostream &operator<<(ostream &os, const Image &right);    //metoda przeciazajaca operator <<

        void flipHorizontal();                                      // metoda pozwalajaca na obrót w poziomie
        void flipVertical();                                        // metoda pozwalajaca na obrót w pionie

    protected:

    private:

        int width, height;                                          // rozmiar obrazu, szerokosc i wysokosc
        byte** ptr;                                                 // wskaznik do wskaznika ptr ( pointer ), ktory bedzie przechowywac adres naszego obiektu, bo pracujemy na obiektach dwuwymariowych, tablica ze wskaznikami do kolejnych tablic
        byte** allock(int width, int height) const;                 // dynamiczna alokacja pamieci
        void deallock() const;                                      // zwolnienie pamieci
};

#endif // IMAGE_H
