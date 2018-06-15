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
	
	friend number operator+(const number&, const number&);
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
	static int count;
	mathExpression() { count++; }
    virtual number calculate() = 0;
	virtual ~mathExpression() {
		count--;
		cout << "dec mE" << endl; 
	};
};
class ZeroMemberOperation : public mathExpression
{
public:
    virtual number calculate() = 0;
	virtual ~ZeroMemberOperation()
	{
		cout << "dec ZMO" << endl; 
	};
};

class OneMemberOperation : public mathExpression
{
	mathExpression* mathexpression;
public:
    virtual number calculate() = 0;
	virtual ~OneMemberOperation() 
	{
		cout << "dec OMO" << endl;
		delete mathexpression;
	};
};

class TwoMemberOperation : public mathExpression
{
protected:
    mathExpression* mathexpression1;
    mathExpression* mathexpression2;
public:
	TwoMemberOperation(mathExpression *me1, mathExpression *me2)
	{
		cout << "con TMO" << endl;
		count++;
		this->mathexpression1 = me1;
		this->mathexpression2 = me2;
	}
    virtual number calculate() = 0;
	virtual ~TwoMemberOperation()
	{
		cout << "dec TMO" << endl;
		delete mathexpression1, mathexpression2;
	}
};

class numberExpression : public ZeroMemberOperation
{
	number value;
public:
	numberExpression(number v) : value(v) 
	{
		cout << "con nE" << endl;
	}
	virtual number calculate() { return value; };
	virtual ~numberExpression() {
		cout << "dec nE" << endl;
	}
};

class Addition : public TwoMemberOperation
{
public:
	Addition(mathExpression *me1, mathExpression *me2) : TwoMemberOperation(me1, me2) { }
	virtual number calculate()
	{
		cout << "con Add" << endl;
		return mathexpression1->calculate() + mathexpression2->calculate();
	}
	virtual ~Addition()
	{
		cout << "dec Add" << endl;
	}
};
class Subtraction : public TwoMemberOperation
{
public:
	Subtraction(mathExpression *me1, mathExpression *me2) : TwoMemberOperation(me1, me2) 
	{
		cout << "con sub" << endl;
	}
	virtual number calculate()
	{
		return mathexpression1->calculate() - mathexpression2->calculate();
	}
	virtual ~Subtraction()
	{
		cout << "dec sub" << endl;
	}
};

class Multiplication : public TwoMemberOperation
{
public:
	Multiplication(mathExpression *me1, mathExpression *me2) : TwoMemberOperation(me1, me2) 
	{
		cout << "con Mul" << endl;
	}
	virtual number calculate()
	{
		return mathexpression1->calculate() * mathexpression2->calculate();
	}
	virtual ~Multiplication()
	{
		cout << "dec Mul" << endl;
	}
};

class Division : public TwoMemberOperation
{
public:
	Division(mathExpression *me1, mathExpression *me2) : TwoMemberOperation(me1, me2) 
	{
		cout << "con Div" << endl;
	}
	virtual number calculate()
	{
		return mathexpression1->calculate() / mathexpression2->calculate();
	}
	virtual ~Division()
	{
		cout << "dec Div" << endl;
	}
};