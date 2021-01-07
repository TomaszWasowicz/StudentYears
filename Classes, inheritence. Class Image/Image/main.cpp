#include <iostream>
#include "Image.hpp"

using namespace std;

int main()
{
    cout << "Hello I am an Image" <<endl;

    Image image2 (10,10);           // image2 zostal zaallockowany, pewna pamiec zostala na niego przeznaczona
    Image image1;

    image2.fillInImage(7);          //wypelnienie obiektu Image znakiem 7
    cout << image2 << endl;         //wyswietlenie obiektu image2

    image1 = image2;                //operator przypisania, image1 rowne jest image2
    cout << image1 << endl;         //wyswietlenie obiektu image1

    image1(1,2) = (5);
    image1(2,3) = (8);
    image1(2,5) = (1);             // zmiana pixela o parametrach 1,4 na wartosc 0
    cout << image1 << endl;         //wypisanie obiektu image1 ze zmienionym pixelem

    byte pixel1 = image1(1,2);       // wypisanie pixela, ktory podmieniamy
    cout << pixel1 << endl;

    byte pixel2 = image1(2,3);       // wypisanie pixela, ktory podmieniamy
    cout << pixel2 << endl;

    byte pixel3 = image1(2,5);       // wypisanie pixela, ktory podmieniamy
    cout << pixel3 << endl;

    image1.flipHorizontal();        //obrot horyzontalny
    cout<<image1<<endl;

    image1.flipVertical();          //obrot wertykalny
    cout<<image1<<endl;



    return 0;
}


