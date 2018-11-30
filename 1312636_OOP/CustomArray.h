#ifndef CUSTOMARRAY_H
#define CUSTOMARRAY_H

template <class T>
class CustomArray
{
private:
	int N;
	T *p_LowerBound, *p_Begin, *p_End, *p_UpperBound, *arr;
public:
	CustomArray(int m_N);
	CustomArray(int m_N, T defaultValue);
	CustomArray(const CustomArray& customArray);
	CustomArray();
	~CustomArray();
	void setDefaultValue(T defaultValue);
	void printArr();
	CustomArray& operator=(CustomArray& t);
	T& operator[] (int x);
	int size();
	T* begin();
	T* end();
	void clear();
	bool empty();
	void resize();
	void push_back(T element);
	void push_front(T element);
	T pop_back();
	T pop_front();
	void insert(int i);
	void erase(int i);
	void sort(bool isIncrease);
};

#endif // !CUSTOMARRAY_H