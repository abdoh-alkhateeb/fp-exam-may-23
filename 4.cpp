/*
*
* This file represents a solution to question no. 4 in the file processing assignment.
* © 2023 Abdulrahman Alkhateeb
*
*/
#include <iostream>
#include <fstream>
#include <cstring>

using std::cin;
using std::cout;
using std::fstream;
using std::ios;

class FileSearcher
{
	fstream file;
	char buffer[257]; // 256 characters maximum + 1 character for '\0' (NULL terminator)
	char key[257]; // 256 characters maximum + 1 character for '\0' (NULL terminator)

public:
	FileSearcher()
	{
		cout << "Enter input filename: ";
		cin >> buffer;
		file.open(buffer, ios::in);

		cout << "Enter key to search for: ";
		cin >> key;
	}

	void run()
	{
		while (file.getline(buffer, 257))
		{
			if (strstr(buffer, key))
			{
				cout << "Found!\n";
				return;
			}
		}
		cout << "Not found!\n";
	}
};

int main(void)
{
	FileSearcher fileSearcher;
	fileSearcher.run();

	return 0;
}