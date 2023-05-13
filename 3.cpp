/*
*
* This file represents a solution to question no. 3 in the file processing assignment.
* © 2023 Abdulrahman Alkhateeb
*
*/
#define _CRT_SECURE_NO_WARNINGS // To ignore warnings about use of strcat
#include <iostream>
#include <fstream>
#include <cstring>

using std::cin;
using std::cout;
using std::fstream;
using std::ios;
using std::remove;
using std::rename;

class LineRemover
{
	fstream file;
	char filename[51]; // 50 characters maximum for filename + 1 character for '\0' (NULL terminator)
	char buffer[81]; // 80 characters maximum per line + 1 character for '\0' (NULL terminator)

public:
	LineRemover()
	{
		cout << "Enter input filename: ";
		cin >> filename;
		file.open(filename, ios::in);
	}

	int run()
	{
		int numOfLines = 0;
		int lineToRemove = 0;

		for (; file.getline(buffer, 81); numOfLines++);
		file.clear(); file.seekg(0, ios::beg);

		cout << "Number of lines: " << numOfLines << '\n';

		cout << "Enter the number of the line you wish to remove: ";
		cin >> lineToRemove;

		fstream tempfile("temp.txt", ios::out);

		for (int i = 1; !file.eof(); i++)
		{
			file.getline(buffer, 81);
			if (file.eof() && strlen(buffer) == 0) break;
			if (i != lineToRemove)
			{
				strcat(buffer, "\n");
				tempfile.write(buffer, strlen(buffer));
			}
		}

		file.close();
		tempfile.close();

		remove(filename);

		return rename("temp.txt", filename);
	}
};

int main(void)
{
	LineRemover lineRemover;
	lineRemover.run();

	return 0;
}