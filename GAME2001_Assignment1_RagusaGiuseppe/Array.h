#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Array
{
public:
	Array<T>(int startSize);
	virtual ~Array<T>();

	void Clear();
	virtual void Add(T item) = 0;
	virtual void Remove(int index) = 0;
	virtual void Search(T item) = 0;
	virtual string GetArrayType() = 0;

	int GetMaxSize();
	int GetExpandValue();
	int GetNumElements();
	void DisplayValues();

protected:
	T* m_pArray;

	int m_maxSize;
	int m_expandValue;
	int m_numElements;

	void Expand();
};

//Array constructor. Both Subclasses will use this constructor
template <typename T>
Array<T>::Array(int startSize) : m_expandValue(1), m_numElements(0) {
	if (startSize > 0) {
		m_maxSize = startSize;
		m_pArray = new T[startSize];
	}
}

//Array destructor. Both subclasses will use this.
template <typename T>
Array<T>::~Array() {
	if (m_pArray != nullptr) {
		delete[] m_pArray;
		m_pArray = nullptr;
	}
	cout << "Deleted Array" << endl;
}

template <typename T>
void Array<T>::Clear() {
	if (m_numElements > 0)
		m_numElements = 0;
}

//get the Max Size of the array
template <typename T>
int Array<T>::GetMaxSize() {
	return m_maxSize;
}

//get the value that the array expands by when the array is full
template <typename T>
int Array<T>::GetExpandValue() {
	return m_expandValue;
}

//get the number of elements currently in the array
template <typename T>
int Array<T>::GetNumElements() {
	return m_numElements;
}

template <typename T>
void Array<T>::DisplayValues() {
	for (int i = 0; i < m_numElements; i++)
		std::cout << m_pArray[i] << " ";
	std::cout << std::endl;
}

template<typename T>
void Array<T>::Expand()
{
	if (m_numElements == m_maxSize) {
		T* newArray = new T[m_maxSize + m_expandValue];

		for (int i = 0; i < m_maxSize; i++)
			newArray[i] = m_pArray[i];

		delete[] m_pArray;
		m_pArray = newArray;
		newArray = nullptr;

		m_maxSize += m_expandValue;
		m_expandValue *= 2;
	}
}

