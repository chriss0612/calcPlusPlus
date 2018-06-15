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
	
	~number() { delete pint, pfloat, pcomplex; };// Making sure to clean up aftr myself

	string toString();
	

	bool isInt() const { return pint != nullptr; }
	bool isFloat() const { return pfloat != nullptr; }
	bool isCompex() const { return pcomplex != nullptr; }
	friend number operator+(const number& a, const number& b);
	friend number operator-(const number& a, const number& b);
	friend number operator*(const number& a, const number& b);
	friend number operator/(const number& a, const number& b);
};


class mathExpression
{
public:
	mathExpression() { }
    virtual number calculate() = 0;
	virtual ~mathExpression() {	}
};
class ZeroMemberOperation : public mathExpression
{
public:
    virtual number calculate() = 0;
	virtual ~ZeroMemberOperation() { }
};

class OneMemberOperation : public mathExpression
{
	mathExpression* mathexpression;
public:
    virtual number calculate() = 0;
	virtual ~OneMemberOperation() { delete mathexpression; };
};

class TwoMemberOperation : public mathExpression
{
protected:
    mathExpression* mathexpression1;
    mathExpression* mathexpression2;
public:
	TwoMemberOperation(mathExpression *me1, mathExpression *me2) {
		this->mathexpression1 = me1;
		this->mathexpression2 = me2;
	}
    virtual number calculate() = 0;
	virtual ~TwoMemberOperation()
	{
		delete mathexpression1;
		delete mathexpression2;
	}
};

class numberExpression : public ZeroMemberOperation
{
	number value;
public:
	numberExpression(number v) : value(v) {	}
	virtual number calculate() { return value; };
};

class Addition : public TwoMemberOperation
{
public:
	Addition(mathExpression *me1, mathExpression *me2) : TwoMemberOperation(me1, me2) { }
	virtual number calculate()
	{
		return mathexpression1->calculate() + mathexpression2->calculate();
	}
};
class Subtraction : public TwoMemberOperation
{
public:
	Subtraction(mathExpression *me1, mathExpression *me2) : TwoMemberOperation(me1, me2) { }
	virtual number calculate()
	{
		return mathexpression1->calculate() - mathexpression2->calculate();
	}
};

class Multiplication : public TwoMemberOperation
{
public:
	Multiplication(mathExpression *me1, mathExpression *me2) : TwoMemberOperation(me1, me2) {}
	virtual number calculate()
	{
		return mathexpression1->calculate() * mathexpression2->calculate();
	}
};

class Division : public TwoMemberOperation
{
public:
	Division(mathExpression *me1, mathExpression *me2) : TwoMemberOperation(me1, me2) {	}
	virtual number calculate()
	{
		return mathexpression1->calculate() / mathexpression2->calculate();
	}
};