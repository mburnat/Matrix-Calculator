#include <iostream>
#include "macierz.h"

using namespace std;

void wypisz(Macierz wzor)
{
	
	for(int i=0; i<wzor.m; i++){
		for(int j=0; j<wzor.n; j++)
			cout << wzor.tablica[i][j]<<"\t";
		cout<<endl;
	}
	cout<<"\n\n";
}

Macierz wczytaj()
{
	int x,y;
	cout<< "\npodaj rozmiar macierzy:"<<endl;
	cin>>x>>y;
	Macierz wynik(x,y);
	for(int i =0; i<x; i++){
		cout<< "Podaj elementy "<<i+1<<" wiersza"<<endl;
		for(int j =0; j<y; j++)
			cin>>wynik.tablica[i][j];
	}
	return wynik;
}

int main()
{
	int a=2;
	int b=2;
	double **tab=new double*[a];
	for(int i=0; i<a; i++)
		tab[i]=new double[b];
	for(int i =0; i<a; i++)
		for(int j =0; j<b; j++)
			tab[i][j]=i*b+j+1;

	Macierz pierwsza;
	wypisz(pierwsza);
	Macierz druga(a,b,tab);
	wypisz(druga);
	
	cout<<"dodawanie:"<<endl;
	wypisz(pierwsza+druga);
	
	cout<<"odejmowanie:"<<endl;
	wypisz(pierwsza-druga);
	cout<<"mnozenie:"<<endl;
	wypisz(pierwsza*druga);
	
	cout<<"mnozenie przez skalar 3:"<<endl;
	wypisz(pierwsza*3);
	
	//cout<<"mnoze :"<<endl;
	//wypisz(pierwsza*pierwsza);
	
	cout<<"potegowanie (do 2):"<<endl;
	wypisz(pierwsza^2);

	cout<<"przyspisanie"<<endl;
	pierwsza=druga;
	wypisz(pierwsza);
	cout<<"Transpozycja:"<<endl;
	wypisz(druga.Trans());
	cout<<"Wyznacznik = "<<pierwsza.wyznacznik()<<endl;

	cout<<"---------------------------------------------------------"<<endl;
	Macierz A=wczytaj();
	Macierz B=wczytaj();
	cout<<endl;
	wypisz(A);
	wypisz(B);
	char znak, wybor;
	do{
		
		cout<<"Wybierz operacje: +, -, *, ^"<<endl;
		cin>>wybor;
		switch(wybor){
		case '+':
			wypisz(A+B);
			break;
		case '-':
			wypisz(A-B);
			break;
		case '*':
			cout<<"mnozenie macierzy:"<<endl;
			wypisz(A*B);
			int p;
			cout <<"Podaj skalar:";
			cin>>p;
			wypisz(A*p);
			wypisz(B*p);
			break;
		case '^':
			int poteg;
			cout<<"Podaj potege";
			cin>>poteg;
			wypisz(A^poteg);
			wypisz(B^poteg);
			break;
		default:
			cout<<"Nie ma takiej opcji"<<endl;
		}
		cout<<"Czy chcesz kontynuowac? [t]"<<endl;
		cin>>znak;
	}while (znak=='t' || znak=='T');
	system("pause");
	return 0;
}