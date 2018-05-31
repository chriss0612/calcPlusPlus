#include <iostream>
#include <string>

using namespace std;

void main(char argc, char **argv)
{
	string flags, ParserArg;

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
	/// **TODO Flag Handeling / Checking**

	//Constructing the string for the parser
	for (int i = flagEnd; i < argc; i++)
	{
		ParserArg += argv[i];
	}

	/// **TODO Send to parser**
	/// **TODO output**
}