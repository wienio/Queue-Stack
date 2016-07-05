#include <iostream>

using namespace std;

struct obiekt
{
	int dane;
	obiekt * nastepny;
};

void push(obiekt *&szczyt, obiekt*& dno)
{
	cout<<"Podaj wartosc do wrzucenia na stos: ";
	int n;
	obiekt *nowy= new obiekt;
	cin>>n;
	nowy->dane=n;
	
	if(szczyt == NULL && dno == NULL)
	{
		szczyt = nowy;
		dno = nowy;
		szczyt->nastepny = NULL;
	}
	else
	{
		szczyt->nastepny=nowy;
		szczyt=szczyt->nastepny;
		szczyt->nastepny=NULL;
	}
}


void pop(obiekt *&szczyt, obiekt*& dno)
{
	obiekt *pom = new obiekt;
	pom=dno;
	

	
	if (dno==NULL && szczyt == NULL)
	{
		cout<<"STOS jest pusty!";
		cout<<endl;
		return;
	}

	if (pom->nastepny == NULL)
	{
		dno =NULL;
		szczyt=NULL;
		return;
	}

	while(pom)
	{
		if(pom ->nastepny->nastepny == NULL)
		{
			break;
		}
		pom=pom->nastepny;
	}
	pom->nastepny=NULL;
	szczyt=pom;
	
}

void show(obiekt *&szczyt, obiekt* dno)
{
	
	if(szczyt == NULL && dno == NULL)
	{
		cout<<"Stos jest pusty!!";
		cout<<endl;
		return;
	}
	
	while(dno)
	{
		cout<<dno->dane<<" ";
		dno=dno->nastepny;
	}
	cout<<endl;
}

int main()
{
	cout<<"Stos wskaznikowy!\n";
	int wybor;
	obiekt *szczyt=NULL;
	obiekt *dno=NULL;
	
	do
	{
	cout<<"Menu:";
	cout<<"\nPodaj co chcesz zrobic: "<<endl;
	cout<<"1)Wrzuc na stos"<<endl;
	cout<<"2)Zdejmij ze stosu"<<endl;
	cout<<"3)Pokaz zawartosc stosu"<<endl;
	cout<<"4)EXIT!"<<endl;
	cin>>wybor;
	
	system("cls");
	
	switch(wybor)
	{
		case 1:
			{
				push(szczyt,dno);
				break;
			}
		case 2:
			{
				pop(szczyt,dno);
				break;
			}
		case 3:
			{
				show(szczyt,dno);
				break;
			}
	}
	
	} while (wybor!=4);
	
}
