#include <iostream>
#include "macierz.h"

using namespace std;

Macierz:: Macierz()
{
	n=2;
	m=2;
	tablica=new double*[m];
	for(int i=0; i<m; i++)
		tablica[i]=new double[n];
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			tablica[i][j]=1;
}

Macierz::Macierz(int _m, int _n, double**wzor)
{
	m=_m;
	n=_n;
	tablica=new double*[m];
	for(int i=0; i<m; i++)
		tablica[i]=new double[n];
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			tablica[i][j]=wzor[i][j];
}
Macierz::Macierz(int _m, int _n)
{
	m=_m;
	n=_n;
	tablica=new double*[m];
	for(int i=0; i<m; i++)
		tablica[i]=new double[n];
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			tablica[i][j]=0;
}

Macierz::Macierz(const Macierz & wzor)
{
	m=wzor.m;
	n=wzor.n;
	tablica=new double*[m];
	for(int i=0; i<m; i++)
		tablica[i]=new double[n];
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			tablica[i][j]=wzor.tablica[i][j];
}

Macierz::~Macierz()
{
	for(int i =0; i<m; i++)
		delete [] tablica[i];
	delete[]tablica;
}

Macierz Macierz::Trans()
{
	int _n=m;
	int _m=n;
	Macierz pomocnicza(_m,_n);
	double **tab=new double*[_m];
	
	for(int i=0; i<_m; i++)
		for(int j=0; j<_n; j++)
			pomocnicza.tablica[i][j]=tablica[j][i];
	return pomocnicza;
}

Macierz Macierz::operator+(Macierz druga)
{
	Macierz pomocnicza(druga);
	for(int i =0; i<m; i++)
		for(int j=0; j<n; j++)
			pomocnicza.tablica[i][j]+=tablica[i][j];
	return pomocnicza;
}

Macierz Macierz::operator-(Macierz druga)
{
	Macierz pomocnicza(m,n,tablica);
	for(int i =0; i<m; i++)
		for(int j=0; j<n; j++)
			pomocnicza.tablica[i][j]-=druga.tablica[i][j];
	return pomocnicza;
}

Macierz & Macierz:: operator=(const Macierz & wzor)
{
	m=wzor.m;
	n=wzor.n;
	tablica=new double*[m];
	for(int i=0; i<m; i++)
		tablica[i]=new double[n];
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			tablica[i][j]=wzor.tablica[i][j];
	return *this;
}

Macierz Macierz::operator*(Macierz druga)
{
	Macierz pomocnicza(n,druga.m);
	
	for(int i =0; i<n; i++)
		for(int j=0; j<n; j++)
			for(int k =0; k<m; k++)
				pomocnicza.tablica[i][j]+=(tablica[i][k]*druga.tablica[k][j]);
	return pomocnicza;
}

Macierz Macierz::operator*(double skalar)
{
	Macierz pomocnicza=*this;
	for(int i =0; i<n; i++)
		for(int j=0; j<m; j++)
			pomocnicza.tablica[i][j]*=skalar;
	return pomocnicza;
}

Macierz Macierz::operator^(int potega)
{
	Macierz pomocnicza(n,m,tablica);
	for(int i =1; i<potega; i++)
		pomocnicza=pomocnicza*pomocnicza;
	return pomocnicza;
}



double Macierz:: wyznacznik()
{
	double wynik=0;
	if(n==2)
		wynik=(tablica[0][0]*tablica[1][1]-tablica[0][1]*tablica[1][0]);
	else
	wynik=(tablica[0][0]*tablica[1][1]*tablica[2][2]+tablica[0][1]*tablica[1][2]*tablica[2][0]+tablica[0][2]*tablica[1][0]*tablica[2][1])-(tablica[0][2]*tablica[1][1]*tablica[2][0]+tablica[0][1]*tablica[1][0]*tablica[2][2]+tablica[0][0]*tablica[1][2]*tablica[2][1]);
	return wynik;
}