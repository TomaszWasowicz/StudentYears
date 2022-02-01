#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;
int main()

{
float x;
float x1;
float x2;

float a;
float b;
float c;
float delta;

cout << "Podaj a"<< endl;
cin >>a;
cout << "Podaj b"<< endl;
cin >>b;
cout << "Podaj c"<< endl;
cin >>c;

delta =((b*b)-(4*a*c));
x=(-b)/(2*a);
x1=(-b-sqrt(delta))/(2*a);
x2=(-b-sqrt(delta))/(2*a);

  if (delta >=0)
    {
  if (delta==0)
  cout << " jedno rozwiazanie " <<x<< " " <<endl;
  else
  cout << " dwa rozwiazania  pierwsze x1 " <<x1<< " drugie x2  " <<x2<< " "  <<endl;
  }
   else
     cout << "  nie ma rozwiazania delta zero" <<endl;
  getch();

}
