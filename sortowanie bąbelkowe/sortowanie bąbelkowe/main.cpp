#include <iostream>
#include<cstdlib>
using namespace std;

void sortowanie_babelkowe(int tab[],int n)
{
	for(int i=0;i<n;i++)
		for(int j=1;j<n-i;j++) //pêtla wewnêtrzna
		if(tab[j-1]>tab[j])
			//zamiana miejscami
			swap(tab[j-1], tab[j]);
}

int main()
{
	int *tab, n;


3
	cout<<"Ile liczb bêdziesz chcia³ posortowaæ? ";
	cin>>n;

	tab = new int [n]; //przydzielenie pamiêci na elementy tablicy
	//wczytanie liczb
	for(int i=0;i<n;i++)
		cin>>tab[i];

	sortowanie_babelkowe(tab,n);

	//wypisanie posortowanych elementów
	for(int i=0;i<n;i++)
          cout<<tab[i]<<" ";

  cout<<endl;
  system("pause");
  return 0;
}
