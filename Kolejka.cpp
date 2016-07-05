#include <iostream>

using namespace std;

struct obiekt
{
	int dane;
	obiekt *nastepny;
};

void push(obiekt *&poczatek, obiekt *& koniec)
{
	cout<<"Podaj wartosc ktora chcesz wrzucic do kolejki: ";
	int n;
	obiekt * nowy = new obiekt;
	cin>>n;
	nowy->dane=n;
	
	if(poczatek == NULL && koniec == NULL)
	{
		poczatek = nowy;
		koniec = nowy;
		poczatek->nastepny=NULL;
	}
	else
	{
		koniec->nastepny=nowy;
		koniec=koniec->nastepny;
		koniec->nastepny=NULL;
	}
	
}

void pop(obiekt *&poczatek, obiekt *& koniec)
{	
	if (poczatek==NULL && koniec == NULL)
	{
		cout<<"Kolejka jest pusta!";
		cout<<endl;
	}
	
	else
	{
		if(poczatek == koniec)
		{
			poczatek=NULL;
			koniec=NULL;
			return;
		}
		poczatek=poczatek->nastepny;
	}
}

void show(obiekt *poczatek,obiekt *koniec)
{
	if (poczatek==NULL && koniec == NULL)
	{
		cout<<"Kolejka jest pusta!";
	}
	
	while(poczatek)
	{
		cout<<poczatek->dane<<" ";
		poczatek=poczatek->nastepny;
	}
	cout<<endl;
}

int main()
{
	int wybor;
	cout<<"Kolejka wskaznikowa!";
	obiekt *poczatek=NULL;
	obiekt *koniec=NULL;
	
	do
	{
	cout<<"Menu:";
	cout<<"\nPodaj co chcesz zrobic: "<<endl;
	cout<<"1)Dodaj do kolejki"<<endl;
	cout<<"2)Wydal z kolejki"<<endl;
	cout<<"3)Pokaz zawartosc kolejki"<<endl;
	cout<<"4)EXIT!"<<endl;
	cin>>wybor;
	
	system("cls");
	
	switch(wybor)
	{
		case 1:
			{
				push(poczatek,koniec);
				break;
			}
		case 2:
			{
				pop(poczatek,koniec);
				break;
			}
		case 3:
			{
				show(poczatek,koniec);
				break;
			}
	}
	
	} while(wybor!=4);
}
