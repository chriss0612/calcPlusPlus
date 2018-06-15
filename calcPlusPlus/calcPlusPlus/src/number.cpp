#include "number.h"
#define OPER(OP) \
if (a.isInt())	\
{	\
	if (b.isInt()) \
		return *a.pint OP *b.pint; \
	if (b.isFloat()) \
		return *a.pint OP *b.pfloat; \
	if (b.isCompex()) \
		return *a.pint OP *b.pcomplex; \
} \
if (a.isFloat()) \
{ \
	if (b.isInt()) \
		return *a.pfloat OP *b.pint; \
	if (b.isFloat()) \
		return *a.pfloat OP *b.pfloat; \
	if (b.isCompex()) \
		return *a.pfloat OP *b.pcomplex; \
} \
if (a.isCompex()) \
{ \
	if (b.isInt()) \
		return *a.pcomplex OP *b.pint; \
	if (b.isFloat()) \
		return *a.pcomplex OP *b.pfloat; \
	if (b.isCompex()) \
		return *a.pcomplex OP *b.pcomplex; \
}\
return number();


number operator+(const number& a, const number& b)
{
	OPER(+)
}

number operator-(const number& a, const number& b)
{
	OPER(-)
}

number operator*(const number& a, const number& b)
{
	OPER(*)
}

number operator/(const number& a, const number& b)
{
	OPER(/ );
}

string number::toString()
{
	if (isInt())
		return std::to_string(*pint);
	if (isFloat())
		return std::to_string(*pfloat);
	if (isCompex())
		return "" + std::to_string(pcomplex->real()) + " + " + std::to_string(pcomplex->imag()) + "j";

	return "Something went wrong";
}