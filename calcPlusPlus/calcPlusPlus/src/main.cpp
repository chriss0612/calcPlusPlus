#include <iostream>
#include <string>
#include "mathExpression.h"

using namespace std;

int preParse(char argc, char **argv);


#define DEBUG
int main(char argc, char **argv)
{
#ifndef DEBUG
	return preParse(argc, argv);
#endif // !DEBUG

	//Debug Area:
	mathExpression *me = new Addition(new numberExpression(100), new Multiplication(new numberExpression(complex(3, 20)), new numberExpression(2)));
	cout << me->calculate().toString() << endl;
	delete me;
	system("pause");
	return EXIT_SUCCESS;
}
