#include <string.h>
#include <iostream>
#include <string>
using namespace std;

void parseRec(char* unparsed, char* flags, uint32_t start, uint32_t end)
{
	std::cout << "Unparsed: " << unparsed << std::endl;
	std::cout << "Flags: " << flags << std::endl;
	/// ** TODO Write Parser **
}

void parse(std::string flags, std::string unparsed) //Wrapper arround the recursiv parser
{
	char* unparsedCstr = new char[unparsed.length() + 1];
	char* flagsCstr = new char[flags.length() + 1];

	memcpy(unparsedCstr, unparsed.c_str(), unparsed.length() + 1);
	memcpy(flagsCstr, flags.c_str(), flags.length() + 1);

	parseRec(unparsedCstr, flagsCstr, 0, (uint32_t) unparsed.length());

	//Cleanups
	delete[] unparsedCstr;
	delete[] flagsCstr;
}

int preParse(char argc, char **argv)
{
	string flags = "";
	string parserString = "";

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
	for (int i = 1; i < argc - 1; i++) //argc -1 so that the last argument will always be directly sent to the parser
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
	if (flags.find('h') != std::string::npos || strchr(argv[argc - 1], 'h')) //check for help flag
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
	return EXIT_SUCCESS;
}
