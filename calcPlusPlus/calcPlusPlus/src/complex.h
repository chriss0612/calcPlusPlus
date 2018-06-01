#pragma once
#include <iostream>
using namespace std;

class complex
{
private:
	float re, im; // Datenelemente
public:
	complex(float rea, float ima) :re(rea), im(ima) {}; // Konstruktoren
	complex() :re(0), im(0) {};
	complex(float rea) :re(rea), im(0) {};
	float real() { return re; }; // Realteil
	float imag() { return im; }; // Imagin�rteil
	float betrag(); // Betrag
	float phase(); // Phase
	complex conj() { return complex(re, -im); }; // konjugiert complex
	void polar(float betrag, float phase); // Polar zu Komponenten
	complex& operator=(const float& as);
	complex operator+=(complex &); // �berladene Operatoren
	complex operator-=(complex &);
	bool fromString(string);
	friend complex operator+(complex, complex); // �berladene Operatoren
	friend complex operator-(complex, complex); // mit zwei oder mehreren Parametern
	friend complex operator*(complex, float);
	friend complex operator*(complex, complex); // k�nnen nur als friend Funktionen
	friend complex operator/(complex, complex); // ausgef�hrt werden !
	friend complex operator/(complex, float);
	friend bool operator==(complex &, complex &);
	friend bool operator!=(complex &, complex &);

	friend ostream &operator<<(ostream &output, const complex &k);
	friend istream &operator>>(istream &output, complex &k);
};