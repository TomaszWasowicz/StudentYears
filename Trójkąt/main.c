#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
float a,b,c;
printf("Podaj dlugosc boku: a \n");
scanf("%f", &a);
printf("Podaj dlugosc boku: b \n");
scanf("%f", &b);
printf("Podaj dlugosc boku: c \n");
scanf("%f", &c);
//sprawdzam czy da sie obliczyc pole trojkata
if (a+b > c && b+c > a && c+a > b)
{
//jesli tak, licze pole trojkata ze wzoru
float pole = sqrt(((a+b+c)/2)*((a+b+c)/2-a)*((a+b+c)/2-b)*((a+b+c)/2-c));
printf("Pole trojkata o bokach %.1f, %.1f, %.1f wynosi: %.4f \n",a,b,c, pole);
}
else printf("Nie da sie utworzyc trojkata z podanych dlugosci bokow!");
return 0;
}
