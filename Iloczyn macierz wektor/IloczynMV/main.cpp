#include <iostream>
#include <time.h>
#include <windows.h>
#include <cstdio>

using namespace std;

void oblicz(int32_t vec[], int32_t mat[][10])
{
    int32_t wynik[10];
    int32_t suma=0;

    for (int x=0; x<10; x++)
    {
        for (int y=0; y<10; y++)
        {
            suma+=(vec[y]*mat[x][y]);
        }
        wynik[x]=suma;
        suma=0;
    }
printf("Wynik\n");
for (int i=0; i<10; i++)
    {
        printf("|%d| ",wynik[i]);
    }
}

int main()
{
    int32_t vect[10];
    int32_t matrix[10][10];

    srand(time(NULL));
//losoj wektory (-100,100)
for (int i=0; i<10; i++)
{
    vect[i]=(rand()%20)-10;
}
//losoj macierz
for (int x=0; x<10; x++)
{
    for (int y=0; y<10; y++)
    {
        matrix[y][x]=(rand()%20)-10;
    }
}

// pokaz
  //wektor
printf("Wektor ->\n");
for (int i=0; i<10; i++)
{
    printf("|%d| ", vect[i]);
}
printf("\n");
  //macierz
printf("Macierz mXn\n");
for (int x=0; x<10; x++)
{
    for (int y=0; y<10; y++)
    {
        printf("%d, ",matrix[x][y]);
    }
    printf("\n");
}
////////////////////////////////////
oblicz( vect, matrix);


    return 0;
}


