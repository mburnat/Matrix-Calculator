#pragma once
#include <iostream>

using namespace std;

class Macierz{
	double **tablica;
	int m,n;
public:
	Macierz();
	Macierz(int,int,double**);
	Macierz(const Macierz &);
	Macierz(int,int);
	~Macierz();
	Macierz Trans();
	Macierz operator+(Macierz);
	Macierz operator-(Macierz);
	Macierz operator*(Macierz);
	Macierz operator*(double);
	Macierz operator^(int);
	Macierz & operator=(const Macierz & wzor);
	double wyznacznik();
	friend void wypisz(Macierz);
	friend Macierz wczytaj();
};