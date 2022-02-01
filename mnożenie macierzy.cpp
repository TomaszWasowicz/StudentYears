#pragma hdrstop
#pragma argsused
#include <iostream>

using namespace std;

int rozmiar;
long **tabA, **tabB, **tabC;

void wprowadz(long **tab);
void wyswietl(long **tab);
void mnozenie();

int main(int argc, char* argv[])
{
cout << "Wprowadz rozmiar macierzy kwadratowych ktore chcesz pomnozyc: ";
cin >> rozmiar;

tabA = new long* [rozmiar];
for (unsigned i = 0; i < rozmiar; ++i)
tabA[i] = new long [rozmiar];

tabB = new long* [rozmiar];
for (unsigned i = 0; i < rozmiar; ++i)
tabB[i] = new long [rozmiar];

tabC = new long* [rozmiar];
for (unsigned i = 0; i < rozmiar; ++i)
tabC[i] = new long [rozmiar];

cout << "\nWprowdzaj wartosci macierzy A wierszami i potwierdzaj ENTEREM " << endl;
wprowadz(tabA);
cout << "\nWprowdzaj wartosci macierzy B wierszami i potwierdzaj ENTEREM " << endl;
wprowadz(tabB);
cout << "\nMacierz A: " << endl;
wyswietl(tabA);
cout << "\nMacierz B: " << endl;
wyswietl(tabB);
cout << "\nIloczynem macierzy A i B jest macierz C: " << endl;
mnozenie();
wyswietl(tabC);

for (unsigned i = 0; i < rozmiar; ++i)
delete[] tabA[i];
delete[] tabA;

for (unsigned i = 0; i < rozmiar; ++i)
delete[] tabB[i];
delete[] tabB;

for (unsigned i = 0; i < rozmiar; ++i)
delete[] tabC[i];
delete[] tabC;

cout << endl;

("pause");
return 0;
}

//----------------------------------------------
void wprowadz(long **tab)
{
 for(int a=0; a<rozmiar; a++)
 {
 cout << "Wiersz " << a+1 << ": " << endl;
     for(int b=0; b<rozmiar; b++)
     {
        cin >> tab[a][b];
     }
 }
}
//-----------------------------------------------
void wyswietl(long **tab)
{
 for(int n=0; n<rozmiar; n++)
 {
        for(int m=0; m<rozmiar; m++)
        {
        cout << tab[n][m] << "  ";
        }
 cout << "\n\n";
 }
}
//-----------------------------------------------
void mnozenie()
{
 for(int i=0; i<rozmiar; i++)
 {
   for(int j=0; j<rozmiar; j++)
     {
       tabC[i][j]=0;
         for(int k=0; k<rozmiar; k++)
          {
       tabC[i][j] += tabA[i][k] * tabB[k][j];
     }
     }
 }
}

