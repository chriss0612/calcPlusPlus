#include "complex.h"
#include <math.h>

float complex::abs()
{
	return sqrt(re*re + im * im);
}

float complex::phase()
{
	return atan(im / re);
}

void complex::polar(float betrag, float phase)
{
	re = betrag * cos(phase);
	im = betrag*sin(phase);
}

complex & complex::operator=(const float & f)
{
	re = f;
	im = 0;
	return *this;
}

complex complex::operator+=(complex &ko)
{
	*this = *this + ko;
	return *this;
}

complex complex::operator-=(complex &ko)
{
	*this = *this - ko;
	return *this;
}

complex operator+(complex k1, complex k2)
{
	return complex(k1.re + k2.re, k1.im + k2.im);
}

complex operator-(complex k1, complex k2)
{
	return complex(k1.re - k2.re, k1.im - k2.im);
}

complex operator*(complex ko, float fl)
{
	return complex(ko.re * fl, ko.im * fl);
}

complex operator*(complex co, int in)
{
	return complex(co.re * in, co.im * in);
}

complex operator*(complex k1, complex k2)
{
	return complex(k1.re * k2.re - k1.im * k2.im, k1.re * k2.im + k1.im * k2.re);
}
complex operator/(complex k1, complex k2)
{
	complex k3 = k2.conj();
	float fl = (k2 * k3).real();
	complex k4 = (k1 * k3);
	return  k4 / fl;
}

complex operator/(complex ko, float fl)
{
	return complex(ko.re/fl,ko.im/fl);
}

complex operator/(complex co, int in)
{
	return complex(co.re / in, co.im / in);
}

bool operator==(complex &k1, complex &k2)
{
	return (k1.re==k2.re) && (k1.im == k2.im);
}

bool operator!=(complex &k1, complex &k2)
{
	return !(k1==k2);
}

ostream & operator<<(ostream & output, const complex & k)
{
	output << k.re << '+' << k.im << 'i';
	return output;
}

istream & operator>>(istream & input, complex & k)
{
	input >> k.re;
	input >> k.im;
	return input;
}
