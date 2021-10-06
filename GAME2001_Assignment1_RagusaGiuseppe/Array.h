#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <assert.h>

using namespace std;

template <typename T>
class Array
{
public:
	Array<T>(int startSize);
	virtual ~Array<T>();

	void Clear();
	virtual void Add(T item) = 0;
	void Pop();
	virtual void Remove(int index) = 0;
	virtual int Search(T item) = 0;
	virtual string GetArrayType() = 0;

	int GetMaxSize();
	int GetExpandValue();
	void SetExpandValue(int value);
	int GetNumElements();
	void DisplayValues();

	void CheckSize();

	T& operator[](int index);

protected:
	T* m_pArray;

	int m_maxSize;
	int m_expandValue;
	int m_numElements;

	void Expand();
};

//Array constructor. Both Subclasses will use this constructor
template <typename T>
Array<T>::Array(int startSize) : m_expandValue(2), m_numElements(0) {
	if (startSize > 0) {
		m_maxSize = startSize;
		m_pArray = new T[startSize];
		memset(m_pArray, 0, startSize * sizeof(T));
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

//"Empties" the array. The elements are still there, but the array treats them as if they don't exist
template <typename T>
void Array<T>::Clear() {
		m_numElements = 0;
}

//Removes the last element of the Array. Different from the actual Remove() function, which removes a specified index
template<typename T>
inline void Array<T>::Pop()
{
	if (m_numElements > 0)
		m_numElements--;
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

//set the value that the array expands by when the array is full
template<typename T>
inline void Array<T>::SetExpandValue(int value)
{
	m_expandValue = value;
}

//get the number of elements currently in the array
template <typename T>
int Array<T>::GetNumElements() {
	return m_numElements;
}

//Print out the array's values
template <typename T>
void Array<T>::DisplayValues() {
	for (int i = 0; i < m_numElements; i++)
		std::cout << m_pArray[i] << " ";
	std::cout << std::endl;
}

//simple function to check if the array needs to expand
template<typename T>
void Array<T>::CheckSize()
{
	if (this->m_numElements == this->m_maxSize) {
		this->Expand();
		cout << "Successfully Expanded" << endl;
	}
}

//The actual expand function
template <typename T>
void Array<T>::Expand()
{
	if (m_numElements == m_maxSize && m_maxSize > 0) {
		//create a larger array with the previous max size and the expand value
		T* newArray = new T[m_maxSize + m_expandValue];
		//assert(newArray != nullptr);

		//copy contents of old array into new array
		//memcpy(newArray, m_pArray, sizeof(T) * m_maxSize);
		for (int i = 0; i < m_numElements; i++)
			newArray[i] = m_pArray[i];

		//delete the old array contents and set its pointer to that of the new array. set the new array pointer to nullptr
		delete[] m_pArray;
		m_pArray = newArray;
		newArray = nullptr;

		//increases the max size by the expand value, then doubles the expand value
		m_maxSize += m_expandValue;
		m_expandValue *= 2;
	}
	return;
}

//Overload the [] operator to access this class like a normal array data structure
template <typename T>
T& Array<T>::operator[](int index) {
	assert(this->m_pArray != nullptr && (index < this->m_numElements && index >= 0));
	return this->m_pArray[index];
}

