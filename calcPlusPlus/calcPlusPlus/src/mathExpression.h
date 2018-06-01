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

	virtual number calculate();
};
