#include "Monomial.h"
#include <iostream>


Monomial::Monomial()
{
	a = 0;
	n = 0;
}

Monomial::Monomial(unsigned int m_N, int m_A) {
	n = m_N;
	a = m_A;
	std::cout << "Don Thuc " << n << "x^" << a << std::endl;
}

Monomial::Monomial(const Monomial& m_Monomial) {
	n = m_Monomial.n;
	a = m_Monomial.a;
}

Monomial::~Monomial()
{
}

Monomial& Monomial::operator=(Monomial &m_Monomial) {
	return m_Monomial;
}

Monomial& Monomial::operator*(Monomial &m_Monomial) {
	Monomial n_Monomial;
	n_Monomial.n = m_Monomial.n + this->n;
	n_Monomial.n = m_Monomial.a * this->a;
	return n_Monomial;
}

Monomial& Monomial::operator/(Monomial &m_Monomial) {
	if (m_Monomial.a == 0)
	{

	}
	Monomial n_Monomial;
	n_Monomial.n = m_Monomial.n - this->n;
	n_Monomial.n = m_Monomial.a / this->a;
	return n_Monomial;
}

Monomial& Monomial::derivative() {
	Monomial n_Monomial;
	n_Monomial.a = a * n;
	n_Monomial.n = n - 1;
	return n_Monomial;
}

Monomial& Monomial::inf_integral() {
	Monomial n_Monomial;
	n_Monomial.a = a / n;
	n_Monomial.n = n + 1;
	return n_Monomial;
}


