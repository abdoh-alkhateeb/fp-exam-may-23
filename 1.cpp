/*
*
* This file represents a solution to question no. 1 in the file processing assignment.
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

class TextReverser
{
	fstream ifile;
	fstream ofile;
	char buffer[257]; // 256 characters maximum + 1 character for '\0' (NULL terminator)

public:
	TextReverser()
	{
		cout << "Enter input filename: ";
		cin >> buffer;
		ifile.open(buffer, ios::in);

		cout << "Enter output filename: ";
		cin >> buffer;
		ofile.open(buffer, ios::out | ios::trunc);
	}

	void run()
	{
		while (!ifile.eof())
		{
			ifile.getline(buffer, 257);
			_strrev(buffer);
			if (strlen(buffer))
			{
				strcat(buffer, "\n");
				ofile.write(buffer, strlen(buffer));
			}
		}
	}
};

int main(void)
{
	TextReverser textReverser;
	textReverser.run();

	return 0;
}