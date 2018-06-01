#include <iostream>
#include <string>
#include <string.h>

#include "calcParser.h"

#define MAX_CHAR 1024

using namespace std;

void main(char argc, char **argv)
{
	string flags="";
	string parserString="";
	char[MAX_CHAR] parserCharArr;

	//Inital syntax check
	if (argc < 2)
	{
		cout << "Expected at least one argument" << endl;
		cout << "Usage: " << argv[0] << " [Flags] <string>" << endl;
		cout << "For Help type: " << argv[0] << " -h" << endl;
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
		else // íf an argument isnt a flag everything after will also not be a flag
		{
			flagEnd = i;
			break;
		}
	}
	if (flags.find('h') != std::string::npos) //check for help flag
	{
		/// **TODO Help**
		cout << "Help not implemented (jet)" << endl;

		return; // if help was called noting else should be done
	}

	/// **TODO Flag Checking**

	//Constructing the string for the parser
	for (int i = flagEnd; i < argc; i++)
	{
		parserString += argv[i];
	}
	strcpy(parserCharArr, parserString.c_str());

	parse(flags, parserCharArr);
	/// **TODO Calculate**
	/// **TODO output**
}
