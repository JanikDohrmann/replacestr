#include <iostream>
#include <string>
#include <regex>
#include <fstream>

using namespace std;

string replace(string input, regex reg, string replace)
{
	return regex_replace(input, reg, replace);
}

int main(int arc, char **argv)
{
	bool consoleInput = false;
	string inputfile = "";
	string arg = "";
	string match = "";
	string repl = "";
	
	for (int i = 0; i < arc; i++)
	{
		arg = argv[i];

		if (i == 1)
		{
			if (arg == "-c")
			{
				consoleInput = true;
			}
			else if (arg == "-f")
			{
				consoleInput = false;
			}
		} 
		else if (i == 2)
		{
			match = arg;
			
		} 
		else if (i == 3)
		{
			repl = arg;
		}
		else if (i == 4)
		{
			inputfile = arg;
		}
	}

	string eingabe;
	regex reg(match);

	if (!consoleInput)
	{
		fstream filestream;
		filestream.open(inputfile, ios::in);

		while (getline(filestream, eingabe))
		{
			cout << replace(eingabe, reg, repl) << endl;
		}

		filestream.close();
	}
	else
	{
		while (getline(cin, eingabe))
		{
			cout << replace(eingabe, reg, repl) << endl;
		}
	}

	return 0;
}