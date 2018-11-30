#include <iostream>
#include "CustomArray.h"

template <class T>
CustomArray<T>::CustomArray(int m_N) {
	N = m_N;
	arr = new T[3 * this->N];
	p_LowerBound = arr;
	p_Begin = arr + N;
	p_End = arr + (2 * N);
	p_UpperBound = arr + (3 * N - 1);
}

template <class T>
CustomArray<T>::CustomArray(int m_N, T defaultValue) {
	N = m_N;
	arr = new T[3 * this->N];
	p_LowerBound = arr;
	p_Begin = arr + N;
	p_End = arr + (2 * N);
	p_UpperBound = arr + (3 * N - 1);
	for (int i = 0; i < this->N; i++)
	{
		*(arr + N + i) = defaultValue;
	}
}

template <class T>
void CustomArray<T>::printArr() {
	T *p_Temp = p_Begin;
	while (p_Temp != p_End) {
		std::cout << *p_Temp;
		p_Temp += 1;
	}
	std::cout << "\n";
	int temp_N = p_End - p_Begin;
	std::cout << temp_N << std::endl;
}

template <class T>
void CustomArray<T>::setDefaultValue(T defaultValue) {
	for (int i = 0; i < this->N; i++)
	{
		arr[this->N + i] = defaultValue;
	}
}

template <class T>
CustomArray<T>::CustomArray() {

}

template <class T>
CustomArray<T>::~CustomArray()
{
	std::cout << "Deconstructor" << std::endl;
	delete p_Begin, p_End, p_LowerBound, p_UpperBound;
	delete[] arr;
}


/* Copy constructor */
template <class T>
CustomArray<T>::CustomArray(const CustomArray<T> &t) {
	N = t.N;
	arr = new T[3 * this->N];
	this->p_LowerBound = arr;
	this->p_Begin = arr + N;
	this->p_End = arr + (2 * N);
	this->p_UpperBound = arr + (3 * N - 1);
	for (int i = 0; i < this->N; i++)
	{
		*(arr + N + i) = *(t.arr + N + i);
	}
}

/* Operator = use deep copy */
template <class T>
CustomArray<T>& CustomArray<T>::operator=(CustomArray<T> &t) {
	this->N = t.N;
	this->arr = new T[3 * this->N];
	this->p_LowerBound = arr;
	this->p_Begin = arr + N;
	this->p_End = arr + (2 * N);
	this->p_UpperBound = arr + (3 * N - 1);
	for (int i = 0; i < this->N; i++)
	{
		*(arr + N + i) = *(t.arr + N + i);
	}
	return *this;
}

/* Operator [] */
template <class T>
T& CustomArray<T>::operator[] (int x) {
	return *(arr + N + x);
}

/* Get size of Custom Array */
template <class T>
int CustomArray<T>::size() {
	return N;
}

template <class T>
T* CustomArray<T>::begin() {
	return p_Begin;
}

template <class T>
T* CustomArray<T>::end() {
	return p_End;
}

template <class T>
void CustomArray<T>::push_back(T element) {
	if (p_End != p_UpperBound)
	{
		*p_End = element;
		p_End = p_End + 1;
	}
	else
	{
		if (p_Begin != p_LowerBound)
		{
			p_Begin = p_Begin - 1;
			for (int i = 0; i < N; i++)
			{
				*(p_Begin + i) = *(p_Begin + i + 1);
			}
			*p_End = element;
			N = N + 1;
		}
		else
		{
			int new_N = p_End - p_Begin;
			CustomArray<T> newObject(new_N);
			for (int i = 0; i < new_N; i++)
			{
				*(newObject.p_Begin + i) = *(p_Begin + i);
			}
			*(newObject.p_End) = element;
			newObject.p_End++;
			//this = newObject;
		}
	}
}

template <class T>
void CustomArray<T>::push_front(T element) {
	if (p_Begin != p_LowerBound)
	{
		p_Begin--;
		*p_Begin = element;
	}
	else
	{
		if (p_End != p_UpperBound)
		{
			p_End++;
			for (int i = 0; i < N; i++)
			{
				*(p_End - i) = *(p_End - i - 1);
			}
			*p_Begin = element;
			N = N + 1;
		}
		else
		{
			int new_N = p_End - p_Begin;
			CustomArray<T> newObject(new_N);
			for (int i = 0; i < new_N; i++)
			{
				*(newObject.p_Begin + i) = *(p_Begin + i);
			}
			newObject.p_Begin--;
			*(newObject.p_Begin) = element;
			//this = newObject;
		}
	}
}

template <class T>
T CustomArray<T>::pop_back() {
	p_End--;
	return *p_End;
}

template <class T>
T CustomArray<T>::pop_front() {
	T temp = *p_Begin;
	p_Begin++;
	return temp;
}

template <class T>
void CustomArray<T>::insert(int index) {

}

template <class T>
void CustomArray<T>::erase(int index) {
	if (index > ((int)N / 2))
	{
		for (int i = 0; i < N - index - 1; i++)
		{
			*(p_Begin + index + i) = *(p_Begin + index + i + 1);
		}
		p_End--;
		N--;
	}
	else
	{
		for (int i = 0; i < index; i++)
		{
			*(p_Begin + index - i) = *(p_Begin + index - i - 1);
		}
		p_Begin++;
		N--;
	}
}

//template <class T>
//void CustomArray<T>::sort(bool isIncrease) {
//	for (int i = 0; i < N - 1; i++)
//	{
//		for (int j = i + 1; j < N; j++)
//		{
//			if ((*(begin + i) > *(begin + j) == isIncrease))
//			{
//				T temp = *(begin + i);
//				*(begin + i) = *(begin + j);
//				*(begin + j) = temp;
//			}
//		}
//	}
//}

template class CustomArray<int>;
