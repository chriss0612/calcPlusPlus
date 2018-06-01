#pragma once

#define MAX_CHAR 1024

class mathExpression
{
    public:
        char syntax[MAX_CHAR];

        Virtual numberExpression calculate() = 0;
};

class ZeroMemberOperation : mathExpression;
class numberExpression : ZeroMemberOperation;
