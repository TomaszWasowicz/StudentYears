#include<iostream>
using namespace std;

int main()
{
int tablica[18] = { 1,4,5,7,9,10,15,18,20,22,24,25,27,29,30,32,34,35 };
int liczba, n = 18, l, p, s;
cout << "Tablica:\n";
for (int i = 0; i < n; i++)
cout << "tablica [" << i+1 << "] = " << tablica[i] << endl;
cout << "Podaj ktory element znalezc: ";
cin >> liczba;
l = 0;
p = n-1;
while (true)
{
if (l > p)
{
cout << "Nie odnaleziono podanego elementu" << endl;
break;
}
s = (l+p)/2;
if (tablica[s] == liczba)
{
cout << "Odnaleziono liczbe " << liczba << " pod indeksem " << s+1 << endl;
break;
}
else if (tablica[s] < liczba)
l = s+1;
else
p = s-1;
}
return 0; // koniec funkcji main i calego programu
}
