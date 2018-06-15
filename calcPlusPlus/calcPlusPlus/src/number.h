#pragma once
#include "complex.h"
#include <string>

//**TODO REWORK number Class completly (current Version is very Hacky ando not expandable)**
class number
{
private:
	int *pint;
	float *pfloat;
	complex *pcomplex;
public:
	number() { pint = nullptr;  pfloat = nullptr; pcomplex = nullptr; }
	number(int x) { pint = new int(x); pfloat = nullptr; pcomplex = nullptr; }
	number(float x) { pint = nullptr; pfloat = new float(x); pcomplex = nullptr; }
	number(complex x) { pint = nullptr; pfloat = nullptr; pcomplex = new complex(x); }
	number(const number& n) {
		if (n.isInt())
			pint = new int(*n.pint);
		else
			pint = nullptr;
		if (n.isFloat())
			pfloat = new float(*n.pfloat);
		else
			pfloat = nullptr;
		if (n.isCompex())
			pcomplex = new complex(*n.pcomplex);
		else
			pcomplex = nullptr;
	}
	number& operator=(number n)
	{
		if (n.isInt())
			pint = new int(*n.pint);
		else
			pint = nullptr;
		if (n.isFloat())
			pfloat = new float(*n.pfloat);
		else
			pfloat = nullptr;
		if (n.isCompex())
			pcomplex = new complex(*n.pcomplex);
		else
			pcomplex = nullptr;
		return *this;
	}
	~number() { delete pint, pfloat, pcomplex; };
	string toString();
	bool isInt() const { return pint != nullptr; }
	bool isFloat() const { return pfloat != nullptr; }
	bool isCompex() const { return pcomplex != nullptr; }
	friend number operator+(const number& a, const number& b);
	friend number operator-(const number& a, const number& b);
	friend number operator*(const number& a, const number& b);
	friend number operator/(const number& a, const number& b);
};