#pragma once
#include "complex.h"
#include <string>


// This should definitly be done better but i dont know how
class number
{
private:
	int *pint;
	float *pfloat;
	complex *pcomplex;
public:
	number()			{pint = nullptr;	pfloat = nullptr;		pcomplex = nullptr; }
	number(int x)		{pint = new int(x);	pfloat = nullptr;		pcomplex = nullptr;}
	number(float x)		{pint = nullptr;	pfloat = new float(x);	pcomplex = nullptr;}
	number(complex x)	{pint = nullptr;	pfloat = nullptr;		pcomplex = new complex(x);}
	
	
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
	
	void operator=(number n)
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
	}
	
	~number();// Making sure to clean up aftr myself

	string toString();
	
	friend number operator+(number, number);
	friend number operator-(number, number);
	friend number operator*(number, number);
	friend number operator/(number, number);

	bool isInt() const { return pint != nullptr; }
	bool isFloat() const { return pfloat != nullptr; }
	bool isCompex() const { return pcomplex != nullptr; }
};

class mathExpression
{
public:
    virtual number calculate() = 0;
};

class ZeroMemberOperation : public mathExpression
{
public:
    virtual number calculate() = 0;
};

class OneMemberOperation : public mathExpression
{
	mathExpression* mathexpression;
public:
    virtual number calculate() = 0;
};

class TwoMemberOperation : public mathExpression
{
protected:
    mathExpression* mathexpression1;
    mathExpression* mathexpression2;
public:
    virtual number calculate() = 0;
};

class numberExpression : public ZeroMemberOperation
{
	number value;
public:
	virtual number calculate() { return value; };
};

class Addition : public TwoMemberOperation
{
public:
	virtual number calculate()
	{
		return mathexpression1->calculate() + mathexpression2->calculate();
	}
};
class Subtraction : public TwoMemberOperation
{
public:
	virtual number calculate()
	{
		return mathexpression1->calculate() - mathexpression2->calculate();
	}
};

class Multiplication : public TwoMemberOperation
{
public:
	virtual number calculate()
	{
		return mathexpression1->calculate() * mathexpression2->calculate();
	}
};

class Division : public TwoMemberOperation
{
public:
	virtual number calculate()
	{
		return mathexpression1->calculate() / mathexpression2->calculate();
	}
};