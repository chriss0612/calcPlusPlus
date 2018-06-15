#include <iostream>
#include <string>
#include <string.h>
#include <windows.h>
#include "mathExpression.h"

using namespace std;


void parse(string flags, string unparsed);

int main(int argc, char **argv)
{
	string flags="";
	string parserString="";

	//Inital syntax check
	if (argc < 2)
	{
		cout << "Expected at least one argument" << endl;
		cout << "Usage: " << argv[0] << " [Flags] <string>" << endl;
		cout << "For Help type: " << argv[0] << " -h" << endl;
		return EXIT_FAILURE;
	}

	//Parsing arguments to flags
	int flagEnd = argc - 1;
	for (int i = 1; i < argc -1; i++) //argc -1 so that the last argument will always be directly sent to the parser
	{
		if (argv[i][0] == '-')
		{
			int pos = 1;
			while (argv[i][pos])
			{
				flags += argv[i][pos];
				pos++;
			}
		}
		else // if an argument isnt a flag everything after will also not be a flag
		{
			flagEnd = i;
			break;
		}
	}
	if (flags.find('h') != std::string::npos || strchr(argv[argc-1],'h')) //check for help flag
	{
		/// **TODO Help**
		cout << "Help not implemented (jet)" << endl;
		return EXIT_SUCCESS; // if help was called noting else should be done
	}

	/// **TODO Flag Checking**

	//Constructing the string for the parser
	for (int i = flagEnd; i < argc; i++)
	{
		parserString += argv[i];
	}

	parse(flags, parserString);
	/// **TODO Calculate**
	/// **TODO output**
	//cout << (number(10) + number(complex(100, 30))).toString() << endl;


	cout << mathExpression::count << endl;
	mathExpression *me = new Addition(new numberExpression(100), new Multiplication(new numberExpression(complex(3, 20)), new numberExpression(2)));
	cout << me->calculate().toString() << endl;
	cout << mathExpression::count << endl;
	delete me;
	cout << mathExpression::count << endl;
	system("pause");
	return EXIT_SUCCESS;
}
