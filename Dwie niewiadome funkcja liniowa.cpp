#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	float a, b;
	short opcja;

	cout<<"Podaj wspolczynnik kierunkowy a: ";
	cin>>a;
	cout<<"Podaj wyraz wolny b: ";
	cin>>b;
	system("cls"); //czyszczenie

	if(b>=0)
		cout<<"Rozpatrywana funkcja: y = "<<a<<"x + "<<b<<endl;
	else
		cout<<"Rozpatrywana funkcja: y = "<<a<<"x "<<b<<endl;

	cout<<endl<<endl;

	cout<<"1 - miejsce zerowe funkcji liniowej"<<endl;
	cout<<"2 - monotonicznosc funkcji liniowej"<<endl;
	cout<<"3 - dziedzina i zbior wartosci funkcji liniowej"<<endl;
	cout<<"4 - wartosci dodatnie i ujemne funkcji liniowej"<<endl;
	cout<<"5 - punkt przeciecia sie z osia Y"<<endl;
	cout<<"6 - wyznaczenie argumentu dla danej wartosci"<<endl;
	cout<<"7 - wyznaczenie wartosci dla danego argumentu"<<endl;
	cout<<endl<<"Wybierz opcje: ";
	cin>>opcja;

	switch(opcja)
	{
		case 1:
			if(a!=0)
				cout<<"Miejsce zerowe = "<<(-b/a)<<endl;
			else
				if(b==0)
					cout<<"Funkcja ma nieskonczenie wiele miejsc zerowych"<<endl;
				else
					cout<<"Funkcja nie ma miejsc zerowych"<<endl;
		break;

		case 2:
			if(a > 0)
				cout<<"Wspolczynnik kierunkowy ma wartosc "<<a<<", wiec funkcja jest rosnaca"<<endl;
			else
				if(a < 0)
					cout<<"Wspolczynnik kierunkowy ma wartosc "<<a<<", wiec funkcja jest malejaca"<<endl;
				else
					cout<<"Wspolczynnik kierunkowy jest rowny 0, wiec funkcja jest stala"<<endl;
		break;

		case 3:
			cout<<"Dziedzina funkcji liniowej jest zbior liczb rzeczywistych"<<endl;
			if(b==0)
				cout<<"Zbiorem wartosci jest tylko jeden element ZW = {"<<b<<"}"<<endl;
			else
				cout<<"Zbiorem wartosci jest zbior liczb rzeczywistych"<<endl;
		break;

		case 4:
			if(a == 0)
			{
				if(b > 0)
					cout<<"Wszystkie wartosci sa dodatnie"<<endl;

				if(b < 0)
					cout<<"Wszystkie wartosci sa ujemne"<<endl;

				if(b==0)
					cout<<"Wszystkie wartosci sa rowne zero"<<endl;

			}
			else
				if(a > 0)
				{
					cout<<"Wartosci dodatnie: x nalezy do ("<<-b/a<<";+infinity)"<<endl;
					cout<<"Wartosci ujemne: x nalezy do (-infinity;"<<-b/a<<")"<<endl;
				}
				else
				{

					cout<<"Wartosci dodatnie: x nalezy do (-infinity;"<<-b/a<<")"<<endl;
					cout<<"Wartosci ujemne: x nalezy do ("<<-b/a<<";+infinity)"<<endl;
				}
		break;

		case 5:
			cout<<"Funkcja przecina sie z osia Y w punkcie: (0, "<<b<<")"<<endl;
		break;

		case 6:
			cout<<"Podaj wartosc y: ";
			double y;
			cin>>y;

			if(a!=0)
				cout<<"Dla y = "<<y<<" x = "<<(y-b)/a<<endl;
			else
				if(y == b)
					cout<<"x nalezy do zbioru liczb rzeczywistych"<<endl;
				else
					cout<<"Nie istnieje wartosc x dla tej wartosci y"<<endl;
		break;

		case 7:
			cout<<"Podaj wartosc x: ";
			double x;
			cin>>x;
			cout<<"Dla x = "<<x<<" y = "<<a*x+b<<endl;
			break;

		default:
			cout<<"Wybrales nieprawidoowa opcje!"<<endl;
	}

	system("PAUSE");
	return EXIT_SUCCESS;
}
