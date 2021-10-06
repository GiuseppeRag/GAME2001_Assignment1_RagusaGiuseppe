#pragma once
#include "Array.h"
#include <string>
#include <iostream>

using namespace std;

//Unordered Array class
template <typename T>
class UnorderedArray : public Array<T>
{
public:
	UnorderedArray(int startSize);
	~UnorderedArray() override;

	void Add(T item) override;
	void Remove(int index) override;
	int Search(T item) override;
	string GetArrayType() override;
};

//Constructor. Doesn't need any additional setup so base cosntructor can be called directly
template<typename T>
UnorderedArray<T>::UnorderedArray(int startSize) : Array<T>(startSize) {}

//Destructor
template<typename T>
UnorderedArray<T>::~UnorderedArray() {
	cout << "Unordered Array Destructor" << endl;
}

//Add function
template<typename T>
void UnorderedArray<T>::Add(T item)
{
	//assert

	//Parent function that performs Expanding if Array is full
	this->CheckSize();

	//new item can be added to end of array
	this->m_pArray[this->m_numElements] = item;
	this->m_numElements++;
	std::cout << "Successfully Added Item" << endl;
}

//Remove function
template<typename T>
void UnorderedArray<T>::Remove(int index)
{
	//check if array is empty first.
	if (this->m_numElements == 0) {
		cout << "No elements to Delete" << endl;
		return;
	}

	//performs a swap between the current index and last index, then decreases the number of elements by 1.
	//can be done because order does not matter, so position of elements is not important
	T temp = this->m_pArray[index];
	this->m_pArray[index] = this->m_pArray[this->m_numElements - 1];
	this->m_pArray[this->m_numElements - 1];
	this->m_numElements--;
	cout << "Successfully Deleted Item" << endl;
}

//Search function
template<typename T>
int UnorderedArray<T>::Search(T item)
{
	//Linear Search. Binary search cannot be done because it only works on an ordered array
	for (int i = 0; i < this->m_numElements; i++) {
		if (this->m_pArray[i] == item) {
			return i;
		}
	}
	return -1;
}

//returns the type of array as a string
template<typename T>
string UnorderedArray<T>::GetArrayType()
{
	return "Unordered Array";
}
