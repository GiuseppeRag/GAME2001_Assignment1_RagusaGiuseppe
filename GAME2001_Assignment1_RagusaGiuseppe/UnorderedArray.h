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

	void Push(T item) override;
	int Search(T item) override;
	string GetArrayType() override;
};

//Constructor. Doesn't need any additional setup so base cosntructor can be called directly
template<typename T>
UnorderedArray<T>::UnorderedArray(int startSize) : Array<T>(startSize) {}

//Destructor
template<typename T>
UnorderedArray<T>::~UnorderedArray() {}

//Add function
template<typename T>
void UnorderedArray<T>::Push(T item)
{
	//Assert to make sure Array is defined before adding
	if (this->Assert(this->m_pArray != nullptr, "Array is undefined, cannot add")) {

		//Parent function that performs Expanding if Array is full
		this->CheckSize();

		//new item can be added to end of array
		this->m_pArray[this->m_numElements] = item;
		this->m_numElements++;
		cout << "Successfully added new value: " << item << endl;
	}
}

//Search function
template<typename T>
int UnorderedArray<T>::Search(T item)
{
	//Linear Search. Binary search cannot be done because it only works on an ordered array
	for (int i = 0; i < this->m_numElements; i++) {
		if (this->m_pArray[i] == item)
			return i;
	}
	return -1;
}

//returns the type of array as a string
template<typename T>
string UnorderedArray<T>::GetArrayType()
{
	return "Unordered Array";
}
