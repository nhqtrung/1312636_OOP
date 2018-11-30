#include <iostream>
#include "Monomial.h"
#include "CustomArray.h"
#include <stdio.h>

using namespace std;
int main() {
	CustomArray<int> m_Arr(3, 5);
	m_Arr.push_back(6);
	m_Arr.push_front(4);
	m_Arr.printArr();
	return 0;
}