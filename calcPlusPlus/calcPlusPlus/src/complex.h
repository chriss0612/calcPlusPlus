#pragma once
#include <iostream>
using namespace std;

class complex
{
private:
	float re, im; // Data Elements
public:
	complex(float rea, float ima) :re(rea), im(ima) {}; //Constructors
	complex() :re(0), im(0) {};
	complex(float rea) :re(rea), im(0) {};
	float real() { return re; }; //Real
	float imag() { return im; }; //Imaginary
	float abs(); // Absolute value
	float phase(); // phase
	complex conj() { return complex(re, -im); }; // conjugate-complex
	void polar(float betrag, float phase); // From polar

	bool fromString(string);
	
	complex& operator=(const float& as); //Operators
	complex operator+=(complex &);
	complex operator-=(complex &);
	friend complex operator+(complex, complex);
	friend complex operator-(complex, complex);
	friend complex operator*(complex, float);
	friend complex operator*(complex, complex);
	friend complex operator/(complex, complex);
	friend complex operator/(complex, float);
	friend bool operator==(complex &, complex &);
	friend bool operator!=(complex &, complex &);

	friend ostream &operator<<(ostream &output, const complex &k);
	friend istream &operator>>(istream &output, complex &k);
};
