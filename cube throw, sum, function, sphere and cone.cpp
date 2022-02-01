#include <iostream>
#include <math.h>
#include <time.h>
#include <windows.h>

using namespace std;

// prototypy funkcji

void rzut_kostka (int *wynik_kostki);
double suma_szeregu(int k);
double funkcja (double x);
double objetosc_kuli(double r);
double objetosc_stozka(double r, double h);

int main()
{
char menu = '\n';

while (menu != '0')
{
    cout << "\n\n Menu wyboru\n";
    cout << "1 - Symulacja 300 rzutow kostka\n";
    cout << "2 - Obliczanie sumy szeregu okreslonej podanym wzorem\n";
    cout << "3 - Obliczanie wartosc funkcji w podanych punktach\n";
    cout << "4 - Obliczanie objetosci kuli lub objetosci stozka\n";
    cout << "0 - koniec\n";
    while ((menu = getc(stdin)) =='\n'){}
    system("cls");
    switch (menu)
    {
    	
    case '1':
	{
    int wynik_kostki[6] = {0,0,0,0,0,0};
    rzut_kostka(wynik_kostki);
    for (int i=0; i<6; i++)
    {
    cout << ("%d wypadlo %d razy \n", i+1, wynik_kostki[i]);
    } 
	cout << ("na 300 rzutow kostka \n" );
    break;
    }

    case '2':
	{
    int k;
    cout << "  j*j+2\ns=-----\n  2*j+3\n"; 
    cout << "Podaj element koncowy wyrazenia: \n";
    cin >> k;
    cout << "Suma szeregu wynosi %.5f \n",suma_szeregu(k);
    break;
    }

    case '3':
	{
    double a, krok;
    int k1;
    cout << "Podaj punkt poczatkowy funkcji (liczba rzeczywista):";
    cin >> a;
    cout << "Podaj co ile ma nastepowac krok (liczba rzeczywista)";
    cin >> krok;
    cout << "Podaj ilosc krokow (liczba calkowita)";
    cin >> k1;
    for (int i=0; i<k1; i++)
    {
    cout << ("%.5f = %.5f \n", (a+i*krok), funkcja(a+i*krok));
    }
    break;
    }

    case '4':
	{
    char wybor = 'a';
    cout << "Co obliczyc? \n 'k'/'K' - Oblicz objetosc kuli \n 's'/'S' - Oblicz objetosc stozka \n";
    while (wybor == 'a' || wybor == '\n'){wybor = getc(stdin);}
    if (wybor=='K') wybor='k';
    if (wybor=='S') wybor='s';

    switch (wybor)
    {
        case 'k':
        case 'K':
		{
         cout << "Podaj promien kuli:";
         double rk;
         cin >> rk;
         cout << ("Objetosc kuli o promieniu r=%.2f wynosi %.5f \n",rk, objetosc_kuli(rk));
         break;
        }
        case 's':
		case 'S':
		{
         cout << "Podaj promien kolistej podstawy stozka:";
         double rs;
         cin >> rs;
         cout << "Podaj wysokosc stozka:";
         double hs;
         cin >> hs;
         cout << ("Objetosc stozka o promieniu kolistej podstawy r=%.2f i wysokosci h=%.2f wynosi %.5f \n",rs,hs, objetosc_stozka(rs,hs));
         break;
                 }
        default: break;
    }
    break;
    }

    default: break;
}}
    return 0;
}


void rzut_kostka (int *wynik_kostki)
{
    int rzut;
    srand(time(NULL));
    for (int i=0; i<300; i++)
    {
        rzut = rand()%6;
        wynik_kostki[rzut]++;
    }
}

double suma_szeregu(int k)
{

    if (k == 1) return ((k*k+2.d)/(2.d*k+3.d));
    else return ((k*k+2.d)/(2.d*k+3.d))+suma_szeregu(k-1);

}

double funkcja (double x)
{
    if (x<-4.d) return cos(x);
    else if (x >= -4.d && x<= 10.d) return 0.25*x*x+1;
    else return x-3.3;
}

double objetosc_kuli(double r)
{
    return (4.d/3.d)*3.14159265*pow(r,3);
}

double objetosc_stozka(double r, double h)
{
    return (1.d/3.d)*3.14159265*pow(r,2)*h;
}

