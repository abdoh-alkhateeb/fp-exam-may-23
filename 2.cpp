/*
*
* This file represents a solution to question no. 2 in the file processing assignment.
* © 2023 Abdulrahman Alkhateeb
*
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::ios;
using std::string;
using std::vector;
using std::sort;

class NameSorter
{
	fstream ifile;
	fstream ofile;
	string buffer;
	vector<string> bufferVector;

public:
	NameSorter()
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
		while (std::getline(ifile, buffer))
		{
			bufferVector.push_back(buffer);
		}

		sort(bufferVector.begin(), bufferVector.end());

		for (auto item : bufferVector)
		{
			ofile << item << endl;
		}
	}
};

int main(void)
{
	NameSorter nameSorter;
	nameSorter.run();

	return 0;
}
