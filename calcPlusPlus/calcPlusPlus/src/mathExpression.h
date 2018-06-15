#pragma once
#include "complex.h"
#include "number.h"

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