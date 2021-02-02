#include <iomanip>
#include <iostream>
#include <cstdlib>

using namespace std;

double f(double x)										// prototyp funkcji
{
  return(x * x + 2 * x);                                // wartosc zwracana
}

int main()                                              // cia�o funkcji
{
  const int N = 1000; 									// przedzia� ca�kowania, wartosc N ( przedzia� ca�kowania ) ma warto�� sta�� 1000, by nie dopu�ci� do modyfikacji
  double xp,xk,s,dx;									// tworz� zmienne xp,xk,s,dx o zakresie podw�jnej precyzji, czyli double
  int i;												//zmienna pomocnicza i

  cout << setprecision(3)      							// precyzja w wypisywaniu liczb zmienno-przecinkowych, tutaj do 3 miejsc po przecinku
       << fixed;               							// wyra�enie "fixed" usuwa notacj� wyk�adnicz� z zadanej liczby do wy�wietlenia

  cout <<"f(x) = x * x + 2 * x dla n = 1000\n\n"		// wypisanie wzoru funkcji i zakresu n
          "Podaj poczatek przedzialu calkowania\n\n"	//wypisuje na ekran polecenie do podania poczatku przedzialu
          "xp = ";
  cin >> xp;											//pobieram wartosc xp do strumienia
  cout << "\nPodaj koniec przedzialu calkowania\n\n"	//wypisuje na ekran polecenie do podania konca przedzialu
          "xk = ";
  cin >> xk;											//pobieram wartosc xk do strumienia
  cout << endl;											// przejscie do nowej linii
  s  = 0;												//deklaracja zmiennej "s", kt�ra ustawiana jest pocz�tkowo na warto�� 0
  dx = (xk - xp) / N;									// utworzenie zmiennej dx, kt�ra jest wzorem na szeroko��  -( "pole trapezu" ) kazdej cz�ci ca�ki
  for(i = 1; i < N; i++) s += f(xp + i * dx);			// p�tla "for" dla podanych wcze�niej warto�ci xp i xk
  s = (s + (f(xp) + f(xk)) / 2) * dx;					// wyliczanie zmiennej "s", kt�ra jest wynikiem oblicze�, czyli warto�ci� ca�ki oznaczonej
  cout << "Wartosc calki wynosi : " << setw(8) << s		// wypisanie i zwrocenie zmiennej "s" - wyniku obliczen
       << endl << endl;									// przej�cie do nowej linii
  system("pause");										// zatrzymanie funkcji
  return 0;
}
