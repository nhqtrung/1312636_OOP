#include "File.h"
#include <fstream>
#include <iostream>
#include "Polynomial.h"

using namespace std;

File::File()
{
}


File::~File()
{
}

void File::readInputFile(string fileName) {
	string line;
	ifstream inputFile;
	inputFile.open(fileName);
	if (inputFile.good()) {
		while (getline(inputFile, line)) {
			string first = line.substr(0, line.find('('));
			cout << first << " ";
			if (line.find(',') != string::npos) {
				string second = line.substr(line.find('(') + 1, line.find(',') - line.find('(') - 1);
				Polynomial f_Poly(second);
				string third = line.substr(line.find(',') + 1, line.find(')') - line.find(',') - 1);
				Polynomial s_Poly(third);
			}
			else
			{
				string second = line.substr(line.find('(') + 1, line.find(')') - line.find('(') - 1);
				Polynomial f_Poly(second);
			}
			cout << "\n";
		}
	}
}
