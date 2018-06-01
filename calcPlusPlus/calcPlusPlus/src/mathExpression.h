#pragma once


class numberExpression;

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
	virtual number calculate();
};

class number
{

};

class integer : public number
{
    public:
        int value;
};
