#pragma once
#include "Array.h"
#include <string>
#include <iostream>

using namespace std;

template <typename T>
class UnorderedArray : public Array<T>
{
public:
	UnorderedArray(int startSize);
	~UnorderedArray() override;

	void Add(T item) override;
	void Remove(int index) override;
	void Search(T item) override;
	string GetArrayType() override;
};

template<typename T>
UnorderedArray<T>::UnorderedArray(int startSize) : Array<T>(startSize) {}

template<typename T>
UnorderedArray<T>::~UnorderedArray() {
	cout << "Unordered Array Destructor" << endl;
}

template<typename T>
void UnorderedArray<T>::Add(T item)
{
	if (this->m_numElements == this->m_maxSize) {
		this->Expand();
		cout << "Successfully Expanded" << endl;
	}

	this->m_pArray[this->m_numElements] = item;
	this->m_numElements++;
	std::cout << "Successfully Added Item" << endl;
}

template<typename T>
void UnorderedArray<T>::Remove(int index)
{
	if (this->m_numElements == 0) {
		cout << "No elements to Delete" << endl;
		return;
	}

	T temp = this->m_pArray[index];
	this->m_pArray[index] = this->m_pArray[this->m_numElements - 1];
	this->m_pArray[this->m_numElements - 1];
	this->m_numElements--;
	cout << "Successfully Deleted Item" << endl;
}

template<typename T>
void UnorderedArray<T>::Search(T item)
{
	for (int i = 0; i < this->m_numElements; i++) {
		if (this->m_pArray[i] == item) {
			cout << "Element Found at index: " << i << endl;
			return;
		}
	}
	cout << "Element not Found" << endl;
}

template<typename T>
string UnorderedArray<T>::GetArrayType()
{
	return "Unordered Array";
}
