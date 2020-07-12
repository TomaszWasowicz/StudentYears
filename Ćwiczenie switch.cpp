#include <iostream>
#include <math.h>
#include <time.h>
#include <windows.h>

///MARKOWIAK PAWEL///
//deklaracja funkcji
void rzut_kostka (int *wynik_kostki);
double suma_szeregu(int k);
double funkcja (double x);
double objetosc_kuli(double r);
double objetosc_stozka(double r, double h);
//koniec deklaracji


int main()
{
char menu = '\n';

while (menu != '0')
{
    printf("\n\n MENU \n");
    printf("1 - RZUT KOSTKA\n");
    printf("2 - SUMA SZEREGU\n");
    printf("3 - FUNKCJA\n");
    printf("4 - OBJETOSCI\n");
    printf("0 - WYJSCIE\n");
    while ((menu = getc(stdin)) =='\n'){}
    system("cls");
    switch (menu)
    {

    case '1':{
    ///PKT.1 RZUT KOSTKA//
    int wynik_kostki[6] = {0,0,0,0,0,0};
    rzut_kostka(wynik_kostki);
    for (int i=0; i<6; i++)
    {
        printf("%d wypadlo %d razy \n", i+1, wynik_kostki[i]);
    } printf("   na 300 rzutow kostka \n" );
    /// ////////////
    break;
    }

    case '2':{
    ///PKT.2 SUMA //
    int k;
    printf("  j*j+2\ns=-----\n  2*j+3\n");
    printf("Podaj element koncowy: \n");
    scanf("%d", &k);
    printf("Suma wynosi %.5f \n",suma_szeregu(k) );
    /// ////////////
    break;
    }

    case '3':{
    ///PKT.3 FUNKCJA//
    double a, krok;
    int k1;

    printf("Podaj punkt poczatkowy (liczba rzeczywista): ");
    scanf("%lf", &a);
    printf("Podaj co ile ma nastepowac krok (liczba rzeczywista) ");
    scanf("%lf", &krok);
    printf("Podaj ilosc krokow (liczba calkowita) ");
    scanf("%d", &k1);
    for (int i=0; i<k1; i++)
    {
        printf("%.5f = %.5f \n", (a+i*krok), funkcja(a+i*krok));
    }
    /// ////////////
    break;
    }

    case '4':{
    ///PKT.4 OBJETOSC//
    char wybor = 'a';
    printf("Co obliczyc? \n 'k' - Oblicz objetosc kuli \n 's' - Oblicz objetosc stozka \n");
    while (wybor == 'a' || wybor == '\n'){wybor = getc(stdin);}
    if (wybor=='K') wybor='k';
    if (wybor=='S') wybor='s';

    switch (wybor)
    {
        case 'k':{
         printf("Podaj promien: ");
         double rk;
         scanf("%lf", &rk);
         printf("Objetosc kuli o promieniu r=%.2f wynosi %.5f \n",rk, objetosc_kuli(rk));
         break;
                 }
        case 's':{
         printf("Podaj promien: ");
         double rs;
         scanf("%lf", &rs);
         printf("Podaj wysokosc: ");
         double hs;
         scanf("%lf", &hs);
         printf("Objetosc stozka o promieniu r=%.2f i wysokosci h=%.2f wynosi %.5f \n",rs,hs, objetosc_stozka(rs,hs));
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

/// FUNKCJE ///
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
/// KONIEC FUNKCJI ///
