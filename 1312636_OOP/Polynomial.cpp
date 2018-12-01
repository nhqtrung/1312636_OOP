#include "Polynomial.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str); // Turn the string into a stream.
	string tok;

	while (getline(ss, tok, delimiter)) {
		internal.push_back(tok);
	}

	return internal;
}

Polynomial::Polynomial()
{
}

Polynomial::Polynomial(string stringPoly) {
	vector<string> internal;
	string tok;
	stringstream ssin(stringPoly);
	CustomArray<Monomial> temp(internal.size());
	while (getline(ssin, tok, ' ')) {
		internal.push_back(tok);
	}
	for (int i = 0; i < internal.size(); i++)
	{
		if (internal.at(i).find("x^") != string::npos)
		{
			string first = internal.at(i).substr(0, internal.at(i).find("x^"));
			cout << first << " ";
			int i_first = stoi(first);
			string second = internal.at(i).substr(internal.at(i).find("x^") + 2);
			cout << second << " || ";
			int i_second = stoi(second);
			Monomial mono(i_first, i_second);
		}
		else {
			string first = internal.at(i).substr(0, internal.at(i).find("x"));
			int i_first = stoi(first);
			cout << first << " ";
			string second = "1";
			int i_second = stoi(second);
			cout << second << " || ";
			Monomial mono(i_first, i_second);
		}
	}
}

Polynomial::~Polynomial()
{
}
