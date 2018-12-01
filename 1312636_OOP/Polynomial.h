#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <string>
#include "CustomArray.h";
#include "Monomial.h";

class Polynomial
{
public:
	Polynomial();
	Polynomial(std::string stringPoly);
	~Polynomial();
private:
	CustomArray<Monomial> *monomialList;
};

#endif // !POLYNOMIAL_H
