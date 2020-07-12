#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
// prototypy funkcji

void losowanie(int p, int k, int tab[], int N);
void wypisanie(int tab[], int N);
void tablica_C(int A[], int B[], int C[], int N);
int suma_i_dod(int A[], int N, int suma, int& liczby_dodatnie);
float sa_i_wieksze(int X[], int N, float& srednia);


main()												// funkcja main
{
	
const int N = 10; 									// zmienna sta³a, wielkosæ tablic
int A[N]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 			// tablica A
int B[N]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 			// tablica B
int C[N]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 			// tablica C
int X[N]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 			// tablica X
int p = 0; 											// zmienna poczatku tablicy
int k = 0; 											// zmienna konca tablicy
int liczby_dodatnie = 0; 							// zmienna licz dodatnich
int suma = 0; 										// zmienna sumy
float srednia = 0; 									// zmienna sredniej arytmetycznej o wielkosci float / double ( jesli potrzeba wiekszej dokladnosci )

cout << "\nPierwszy element tablicy A: " << endl;
cin >> p; 											// wprowadzenie do strumienia zmiennej p - poczatku tablicy
cout << "\nOstatni element tablicy A: "<< endl;
cin >> k;											// wprowadzenie do strumienia zmiennej k - konca tablicy
losowanie(p, k, A, N);								// funkcja losujaca elementy z podanego przedzialu
cout << "\nTablica A: " << endl;
wypisanie(A, N);									// funkcja wypisujaca elementy z tablicy A

cout << "\nPierwszy element tablicy B: " << endl;	//tablica B
cin >> p;											// wprowadzenie do strumienia zmiennej p - poczatku tablicy
cout << "\nOstatni element tablicy B: " << endl;
cin >> k;											// wprowadzenie do strumienia zmiennej k - konca tablicy
losowanie(p, k, B, N);								// funkcja losujaca elementy z podanego przedzialu
cout << "\nTablica B: " << endl;	
wypisanie(B, N);									// funkcja wypisujaca elementy z tablicy B

tablica_C(A, B, C, N);								//Funkcja tworzaca tablice C
cout << "\nTablica C: " << endl;
wypisanie(C, N);									// funkcja wypisujaca elementy z tablicy C

cout << "\nSuma liczb dodatnich w tablicy A: " << suma_i_dod(A, N, suma, liczby_dodatnie) << endl;
cout << "\nIlosc liczb dodatnich w tablicy A: " << liczby_dodatnie << endl;

cout << "\nPierwszy element tablicy X: " << endl;	//tablica X
cin >> p;											// wprowadzenie do strumienia zmiennej p - poczatku tablicy
cout << "\nOstatni element tablicy X: " << endl;
cin >> k;											// wprowadzenie do strumienia zmiennej k - konca tablicy
losowanie(p, k, X, N);								// funkcja losujaca elementy z podanego przedzialu
cout << "\nTablica X: " << endl;
wypisanie(X, N);									// funkcja wypisujaca elementy z tablicy X
sa_i_wieksze(X, N, srednia);						// funkcja licz¹ca œredni¹ arytmetyczn¹ i liczby wiêksze
cout << "\nSrednia arytmetyczna dla tablicy X wynosi: " << srednia << endl;
cout << "\nW tablicy X jest tyle elementow wiekszych od sredniej: " << sa_i_wieksze(X, N, srednia) << endl;

return 0;
}

// funkcje
void losowanie(int p, int k, int tab[], int N)
{
    srand(time(NULL));								// srand w main
    for(int i=0; i<N; i++)							//pêtla for
	{
    tab[i] = ( rand() % ((k - p) + 1 ) + p ) ; 		//losowanie =(( rand() %( stop - start ) + 1 ) + start );
    }
}

void wypisanie(int tab[], int N)
{
    for(int i=0; i<N; i++) cout << " " << endl;							//pêtla for
	{
    cout << tab[i] << "  " << endl; 						// wypisanie tablicy
    }
}

void tablica_C(int A[], int B[], int C[], int N) 	// tablica C powstaje poprzez wybor mniejszych wartosci z tablic A i B
{
    for(int i=0; i<N; i++)							//pêtla for
	{
	if (A[i] < B[i]) 								// jeœli elementy tablicy A s¹ mniejsze od elementów tablicy B
	C[i] = A [i];  									// to elementy tablicy A to elementy tablicy C
	else if (A[i] > B[i]) 							// w innym wypadku jeœli elementy tablicy B s¹ mniejsze od elementów tablicy A
	C[i] = B [i];  									// to elementy tablicy B to elementy tablicy C
    }
//// co jesli A = B , 
}

int suma_i_dod(int A[], int N, int suma, int& liczby_dodatnie) // referencja 
{
    for(int i=0; i<N; i++)
	{
    if(A[i]>0)  									// jeœli elementy tablicy s¹ dodatnie ( wieksze od zera )
	{
    suma += A[i]; 									// to oblicz sumê tych elementów tablicy A
    liczby_dodatnie++;
    }
    }
    return suma; 									// zwroc sume przez return
}

float sa_i_wieksze(int X[], int N, float& srednia)  // referencja  MOZE BYC INT'em
{
	int ilosc = 0; 									// zmienna ilosc, niezadeklarowana w funkcji main
	for(int i=0; i<N; i++)							// petla for
	{
    srednia += X[i]; 								// suma elementow w tablicy X
    }	
    srednia = srednia/N; 							// iloraz sumy elementow przez liczbe elementow
    for(int i=0; i<N; i++)
	{
    if (X[i] > srednia) ilosc++;					// jesli elementy tablicy s¹ wiêksze ni¿ œrednia arytmetyczna, 
    }
    return ilosc;									// zwróæ ich iloœæ
}	
	


