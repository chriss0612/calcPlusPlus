#include <iostream>
#include <string>

using namespace std;

void main(char argc, char **argv)
{
	string flags(), arg();
	system("pause");
	if (argc < 2)
	{
		cout << "Expected at least one argument" << endl;
		cout << "Usage: " << argv[0] << " [Flags] <string>" << endl;
		cout << "For Help type: " << argv[0] << " -h" << endl;
	}

	system("pause");
	for (int i = 1; i < argc; i++)
	{
		if (argv[i][0])
		{

		}
	}

}