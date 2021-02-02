#include <iomanip>
#include <iostream>
#include <cstdlib>

using namespace std;

double f(double x)										// prototyp funkcji
{
  return(x * x + 2 * x);                                // wartosc zwracana
}

int main()                                              // cia³o funkcji
{
  const int N = 1000; 									// przedzia³ ca³kowania, wartosc N ( przedzia³ ca³kowania ) ma wartoœæ sta³¹ 1000, by nie dopuœciæ do modyfikacji
  double xp,xk,s,dx;									// tworzê zmienne xp,xk,s,dx o zakresie podwójnej precyzji, czyli double
  int i;												//zmienna pomocnicza i

  cout << setprecision(3)      							// precyzja w wypisywaniu liczb zmienno-przecinkowych, tutaj do 3 miejsc po przecinku
       << fixed;               							// wyra¿enie "fixed" usuwa notacjê wyk³adnicz¹ z zadanej liczby do wyœwietlenia

  cout <<"f(x) = x * x + 2 * x dla n = 1000\n\n"		// wypisanie wzoru funkcji i zakresu n
          "Podaj poczatek przedzialu calkowania\n\n"	//wypisuje na ekran polecenie do podania poczatku przedzialu
          "xp = ";
  cin >> xp;											//pobieram wartosc xp do strumienia
  cout << "\nPodaj koniec przedzialu calkowania\n\n"	//wypisuje na ekran polecenie do podania konca przedzialu
          "xk = ";
  cin >> xk;											//pobieram wartosc xk do strumienia
  cout << endl;											// przejscie do nowej linii
  s  = 0;												//deklaracja zmiennej "s", która ustawiana jest pocz¹tkowo na wartoœæ 0
  dx = (xk - xp) / N;									// utworzenie zmiennej dx, która jest wzorem na szerokoœæ  -( "pole trapezu" ) kazdej czêœci ca³ki
  for(i = 1; i < N; i++) s += f(xp + i * dx);			// pêtla "for" dla podanych wczeœniej wartoœci xp i xk
  s = (s + (f(xp) + f(xk)) / 2) * dx;					// wyliczanie zmiennej "s", która jest wynikiem obliczeñ, czyli wartoœci¹ ca³ki oznaczonej
  cout << "Wartosc calki wynosi : " << setw(8) << s		// wypisanie i zwrocenie zmiennej "s" - wyniku obliczen
       << endl << endl;									// przejœcie do nowej linii
  system("pause");										// zatrzymanie funkcji
  return 0;
}
