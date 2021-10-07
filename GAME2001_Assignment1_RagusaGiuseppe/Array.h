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
	virtual void Push(T item) = 0;
	void Pop();
	void Remove(int index);
	virtual int Search(T item) = 0;
	virtual string GetArrayType() = 0;

	int GetMaxSize();
	int GetExpandValue();
	void SetExpandValue(int value);
	int GetNumElements();
	void DisplayValues();

	T& operator[](int index);

protected:
	T* m_pArray;

	int m_maxSize;
	int m_expandValue;
	int m_numElements;

	void CheckSize();
	void Expand();
	bool Assert(bool condition, string errorMessage);
};

//Array constructor. Both Subclasses will use this constructor
template <typename T>
Array<T>::Array(int startSize) : m_expandValue(2), m_numElements(0) {
	if (Assert(startSize > 0, "Array size must be greater than 0!")) {
		m_maxSize = startSize;
		m_pArray = new T[startSize];
	}
}

//Array destructor. Both subclasses will use this.
template <typename T>
Array<T>::~Array() {
	if (Assert(m_pArray != nullptr, "Array is not defined, cannot delete")) {
		delete[] m_pArray;
		m_pArray = nullptr;
		cout << "Deleted Array" << endl;
	}
}

//"Empties" the array. The elements are still there, but the array treats them as if they don't exist
template <typename T>
void Array<T>::Clear() {
		m_numElements = 0;
		cout << "Array Cleared" << endl;
}

//Removes the last element of the Array. Different from the actual Remove() function, which removes a specified index
template<typename T>
inline void Array<T>::Pop()
{
	if (Assert(m_numElements > 0, "Cannot remove element because the array is empty")) {
		m_numElements--;
		cout << "Value: " << m_pArray[m_numElements] << " was popped from the array" << endl;
	}
}

//Remove function. Different from the Pop() function, which only removes the last element in the list
template <typename T>
void Array<T>::Remove(int index)
{
	//don't proceed if array is empty
	if (!Assert(m_numElements > 0, "Cannot remove element because the array is empty"))
		return;

	cout << "Value " << m_pArray[index] << " was removed from the array" << endl;
	//shift all elements down by one (replacing the old value) and then decreasing the number of elements by 1
	for (int i = index; i < this->m_numElements - 1; i++)
		this->m_pArray[i] = this->m_pArray[i + 1];
	this->m_numElements--;
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
template <typename T>
void Array<T>::SetExpandValue(int value) {
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
	if(Assert(m_numElements > 0, "Array is Empty. Nothing to Print")) {
		cout << "Array Contents: ";
		for (int i = 0; i < m_numElements; i++)
			cout << m_pArray[i] << ", ";
		cout << endl;
	}
}

//simple function to check if the array needs to expand
template<typename T>
void Array<T>::CheckSize()
{
	if (this->m_numElements == this->m_maxSize) {
		cout << "Array is full, and therefore will be expanded" << endl;
		this->Expand();
	}
}

//The actual expand function
template <typename T>
void Array<T>::Expand()
{
	if (Assert(m_numElements == m_maxSize && m_maxSize > 0, "Array Still has room, no need to Expand")) {
		//create a larger array with the previous max size and the expand value
		T* newArray = new T[m_maxSize + m_expandValue];

		//copy contents of old array into new array
		memcpy(newArray, m_pArray, sizeof(T) * m_maxSize);

		//delete the old array contents and set its pointer to that of the new array. set the new array pointer to nullptr
		m_pArray = newArray;
		newArray = nullptr;

		//increases the max size by the expand value, then doubles the expand value
		m_maxSize += m_expandValue;
		m_expandValue *= 2;
	}
	return;
}

//Assert function. Prints an error if the condition is not valid, but does not crash the program
template <typename T>
bool Array<T>::Assert(bool condition, string errorMessage)
{
	if (!condition) {
		cout << errorMessage << endl;
		return false;
	}
	return true;
}

//Overload the [] operator to access this class like a normal array data structure
template <typename T>
T& Array<T>::operator[](int index) {
	assert(this->m_pArray != nullptr && (index <= this->m_numElements && index >= 0));
	return this->m_pArray[index];
}

