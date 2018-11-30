#ifndef MONOMIAL_H
#define MONOMIAL_H

class Monomial
{
private:
	unsigned int n;
	float a;
public:
	Monomial();
	Monomial(unsigned int m_N, float m_A);
	Monomial(const Monomial& m_Monomial);
	~Monomial();
	Monomial& operator=(Monomial& m_Monomial);
	Monomial& operator*(Monomial& m_Monomial);
	Monomial& operator/(Monomial& m_Monomial);
	Monomial& derivative();
	Monomial& inf_integral();
};

#endif // !MONOMIAL_H