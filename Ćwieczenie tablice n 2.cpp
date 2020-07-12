#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void losowanie_tablicy_A (float A[][8]);
void losowanie_tablicy_B (float B[][8]);
float srednia (float A[][8]);
void tablica_C (float B[][8], float C[]);
void tablica_D (float B[][8], float D[]);
void uporzadkowanie_Aup (float A [][8]);
void wypisz_tablice ( float tab [][8] );

main()
{
	
float A [8][8];
float B [5][8];
float C [8];
float D [5];
float i;
float j;
int wiersze = 0;

cout << "\nTablica A: " << endl;		
losowanie_tablicy_A (A);
wypisz_tablice (A);
cout << "\nTablica B: " << endl;
losowanie_tablicy_B (B);
wypisz_tablice (B);
srednia (A);
cout << "\nsrednia arytmetyczna elementow pod przekatna wynosi: " << srednia (A) << endl;
cout << "\nTablica C: " << endl;
tablica_C (B, C);
cout << "\nTablica D: " << endl;
tablica_D (B, C);
cout << "\nuporzadkowana Tablica Aup: " << endl;
uporzadkowanie_Aup (A);
wypisz_tablice (A);

return 0;
}


void losowanie_tablicy_A (float A [][8]) //tablica A
{
	srand(time(NULL));
    for(int i = 0; i < 8; i++)
	{
    for(int j = 0; j < 8; j++)
	{
    A[i][j] = float(rand()%51)/float(10);
    }
    }
}

void losowanie_tablicy_B (float B [][8]) // tablica B
{
	srand(time(NULL));
    for(int i = 0; i < 5; i++)
	{
    for(int j = 0; j < 8; j++)
	{
    B[i][j] = float(rand()%51)/float(10);
    }
    }
}
 
float srednia (float A [][8]) // srednia arytmetyczna
{
    float srednia = 0.0;
    for( int i = 0; i < 8; i++)
    {
    srednia += A [i+1][i];	
	};
    return srednia/7;
}

void tablica_C (float B[][8], float C[]) // suma elementow 
{
	float elementy_C = 0.0;
	for(int j = 0; j < 8; j++)
	{
    elementy_C = B [0][j];
    for(int i = 0; i < 5; i++)
	{
	elementy_C += B[i][j];
	}
	C[j] = elementy_C;		
    cout << C[j] <<" ";
    }
    cout << endl;
}	

void tablica_D (float B[][8], float D[]) // najmniejszy element
{
	float elementy_D = 0.0;
	for(int i = 0; i < 5; i++)
	{
	elementy_D = B [i][0];
	for(int j = 0; j < 8; j++)
	{
	elementy_D = min(elementy_D, B[i][j]);		
	}	
	D[i] = elementy_D;
	cout << D[i] << " ";		
	}	
	cout << endl;	
}

void uporzadkowanie_Aup (float A [8][8]) // nie jestem pewien czy ta eksperymentalna funkcja dobrze porz¹dkuje
{
	for (int i = 0; i < 8; i++)
	{
	float tymczasowa = A[i][i];
	int pozycja = i;
	for (int j=i+1; j<8; j++)
	{
	if (tymczasowa > A[j][j])
	{
	tymczasowa = A[j][j];
	pozycja = j;	
	}	

	}
	swap (A[i][i], A[pozycja][pozycja]);
    }

}

void wypisz_tablice ( float tab[][8]) // planowa³em pocz¹tkowo zrobiæ program bez funkcji wyœwietlaj¹cej
{
	for(int i = 0; i < 8; i++) // , ale zwyk³e wyœwietlanie dla tablicy Aup: cout << Aup[i][j] <<" "; nie podawa³o wyników macierzy, lecz tylko przek¹tn¹
	{
	for (int j=0; j < 8; j++)
	{
	cout << tab[i][j] << " ";
	}
	cout << "\n";
	}
}


