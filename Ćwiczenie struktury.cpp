#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <math.h>

using namespace std;

struct student 
{
string nazwisko;
float oceny[3];
float srednia;
};

void podaj_dane_studentow(student* tab, int N);
float srednia_ocen_studentow(student* tab, int N);
int srednia_powyzej_srednich(student* tab, int N, float srednia_ocen_studentow);
void wyswietl_dane_studentow(student* tab, int N);
void najwyzsza_srednia(student* tab, int N);
void wyswietl_studenta(student* tab, int N);

main()
{

int N = 0;
cout << "Podaj liczbe studentow";
cin >> N;
student * klasa = new student[N];

podaj_dane_studentow(klasa, N);

srednia_ocen_studentow(klasa, N);

float sredniastudentow = srednia_ocen_studentow(klasa, N);
cout << "\nSrednia ocen wszystkich studentow wynosi " << sredniastudentow;

srednia_powyzej_srednich (klasa, N, sredniastudentow);
cout << " \n\nLiczba studentow ze srednia wyzsza niz srednia wszystkich studentow." << srednia_powyzej_srednich (klasa, N, sredniastudentow) << endl;

wyswietl_dane_studentow(klasa, N);

najwyzsza_srednia(klasa, N);

wyswietl_studenta(klasa, N);

return 0;
}

void podaj_dane_studentow(student* tab, int N)
{
    for(int i=0; i<N; i++)
	{
    cout << "\nPodaj nazwisko " << i+1 << ". studenta: ";
    cin >> tab[i].nazwisko;
    for(int x=0; x<3; x++)
	{
    double oceny[7] = { 2, 2.5, 3, 3.5, 4, 4.5, 5 };
    tab[i].oceny[x] = oceny[rand()%7];
    }
    tab[i].srednia = (tab[i].oceny[0] + tab[i].oceny[1] + tab[i].oceny[2])/ 3;
    }
}

float srednia_ocen_studentow(student* tab, int N)
{
    float suma = 0;
    for(int i=0; i<N; i++)
	{
    suma += tab[i].oceny[0] + tab[i].oceny[1] + tab[i].oceny[2];
    }
    return ( suma /(N*3.0) );
}

int srednia_powyzej_srednich(student* tab, int N, float srednia_ocen_studentow)
{
    float srednia_powyzej_srednich = 0;
    for(int i=0; i<N; i++)
	{
    if(tab[i].srednia > srednia_ocen_studentow) srednia_powyzej_srednich++;
    }
    return srednia_powyzej_srednich;
}

void wyswietl_dane_studentow(student* tab, int N)

{
    for(int i=0; i<N; i++)
	{
    cout << "\nstudent " << endl;
	cout << tab[i].nazwisko << endl; 
	cout << "Srednia: " << endl;
	cout << tab[i].srednia << endl;
	cout << "Oceny: " << tab[i].oceny[0] << ", " << tab[i].oceny[1] << ", " << tab[i].oceny[2] << endl;
    }
}

void najwyzsza_srednia(student* tab, int N)
{
    int x = 0;
    for(int i = 1; i < N; i++)
	{
    if(tab[x].srednia < tab[i].srednia)
    x = i;
    }
    cout << "student: " << tab[x].nazwisko << endl;
    cout << "posiada najwyzsza srednia: " << tab[x].srednia << endl;
}

void wyswietl_studenta(student* tab, int N)
{
    string nazwisko = "";
    cout << "\n\npodaj nazwisko szukanego studenta: ";
    cin >> nazwisko;
    for(int i=0; i<N; i++)
	{
    if(tab[i].nazwisko == nazwisko)
	{
    cout << "\nstudent " << endl;
	cout << tab[i].nazwisko << endl; 
	cout << "Srednia: " << endl;
	cout << tab[i].srednia << endl;
	cout << "Oceny: " << tab[i].oceny[0] << ", " << tab[i].oceny[1] << ", " << tab[i].oceny[2] << endl;
	break;
    }
	else (tab[i].nazwisko != nazwisko);
	cout << "nie ma takiego nazwiska" << endl;
	break;
	}
    
};












