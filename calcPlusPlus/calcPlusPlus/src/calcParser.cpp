#include "calcParser.h"
#include <string.h>

#include <iostream>

void parseRec(char* unparsed, char* flags, uint32_t start, uint32_t end);

void parse(string flags, string unparsed) //Wrapper arround the recursiv parser
{
	char* unparsedCstr = new char[unparsed.length() + 1];
	char* flagsCstr = new char[flags.length() + 1];

	memcpy(unparsedCstr, unparsed.c_str(), unparsed.length() + 1);
	memcpy(flagsCstr, flags.c_str(), flags.length() + 1);

	parseRec(unparsedCstr, flagsCstr, 0, unparsed.length());

	//Cleanups
	delete[] unparsedCstr;
	delete[] flagsCstr;
}

void parseRec(char* unparsed, char* flags, uint32_t start, uint32_t end)
{
	std::cout << "Unparsed: " << unparsed << endl;
	std::cout << "Flags: " << flags << endl;
	/// ** TODO Write Parser **
}
