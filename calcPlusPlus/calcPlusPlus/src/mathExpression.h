#pragma once


class number
{

};

class integer : public number
{
    public:
        int value;
};

class mathExpression
{
    public:
        virtual number calculate() = 0;
};

class ZeroMemberOperation : public mathExpression
{
	virtual number calculate() = 0;
};

class numberExpression : public ZeroMemberOperation
{
    number value;

	virtual number calculate() = 0;
};
class OneMemberOperation : public mathExpression
{
	mathExpression* mathexpression;

	virtual number calculate() = 0;
};

class TwoMemberOperation : public mathExpression
{
	mathExpression* mathexpression1;
	mathExpression* mathexpression2;

	virtual number calculate() = 0;
};