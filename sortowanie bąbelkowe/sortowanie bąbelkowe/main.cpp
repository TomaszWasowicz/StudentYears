#include <iostream>
#include<cstdlib>
using namespace std;

void sortowanie_babelkowe(int tab[],int n)
{
	for(int i=0;i<n;i++)
		for(int j=1;j<n-i;j++) //p�tla wewn�trzna
		if(tab[j-1]>tab[j])
			//zamiana miejscami
			swap(tab[j-1], tab[j]);
}

int main()
{
	int *tab, n;


3
	cout<<"Ile liczb b�dziesz chcia� posortowa�? ";
	cin>>n;

	tab = new int [n]; //przydzielenie pami�ci na elementy tablicy
	//wczytanie liczb
	for(int i=0;i<n;i++)
		cin>>tab[i];

	sortowanie_babelkowe(tab,n);

	//wypisanie posortowanych element�w
	for(int i=0;i<n;i++)
          cout<<tab[i]<<" ";

  cout<<endl;
  system("pause");
  return 0;
}
