#pragma once

#define MAX_CHAR 1024

class numberExpression;

class mathExpression
{
    public:
        char syntax[MAX_CHAR];

        virtual numberExpression calculate() = 0;
};

class ZeroMemberOperation : mathExpression
{

};

class numberExpression : ZeroMemberOperation
{

};

class integer : numberExpression
{
    public:
        int value;
        string numberSystem;
};
