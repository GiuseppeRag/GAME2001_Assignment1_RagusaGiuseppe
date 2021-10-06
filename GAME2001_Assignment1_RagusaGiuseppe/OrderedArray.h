#pragma once
#include "Array.h"

template <typename T>
class OrderedArray : public Array<T>
{
public:
	OrderedArray(int startSize, bool allowDupes);
	~OrderedArray() override;

	void Add(T item) override;
	void Remove(int index) override;
	int Search(T item) override;
	string GetArrayType() override;

	void SetAllowDuplicates(bool allow);
	bool AllowDuplicates();
private:
	bool m_allowDuplicates;

	bool CheckForDuplicate(T item);
	int BinarySearch(int startIndex, int endIndex, T item);
};

//Constructor. Uses an additional boolean for allowing duplicates
template <typename T>
OrderedArray<T>::OrderedArray(int startSize, bool allowDupes) : Array<T>(startSize)
{
	m_allowDuplicates = allowDupes;
}

//Destructor
template <typename T>
OrderedArray<T>::~OrderedArray()
{
	cout << "Ordered Array Destructor" << endl;
}

//Add function
template <typename T>
void OrderedArray<T>::Add(T item)
{
	//assert
	if (!m_allowDuplicates && Search(item) != -1) {
		cout << "Duplicates are not allowed in this Array!" << endl;
		return;
	}

	//Parent function that performs Expanding if Array is full
	this->CheckSize();

	int key;

	for (int i = 0; i <= this->m_numElements; i++) {
		if (this->m_pArray[i] < item) {
			key = i;
			break;
		}
	}

	for (int j = this->m_numElements; j >= key; j--) {
		this->m_pArray[j] = this->m_pArray[j - 1];
	}

	this->m_pArray[key] = item;
	//shift the elements down while also checking the new value against the previous values to find the appropriate spot
	/*for (int i = this->m_numElements; i >= 0; i--) {
		if (item > this->m_pArray[i]) {
			this->m_pArray[i + 1] = item;
			break;
		}
		this->m_pArray[i + 1] = this->m_pArray[i];
	}*/
	this->m_numElements++;
}

//Remove function. Unlike Unordered Array, elements need to be shifted down to maintain order
template <typename T>
void OrderedArray<T>::Remove(int index)
{
	//don't proceed if array is empty
	if (this->m_numElements == 0) {
		cout << "No elements to Delete" << endl;
		return;
	}

	//shift all elements down by one (replacing the old value) and then decreasing the number of elements by 1
	for (int i = index; i < this->m_numElements - 1; i++)
		this->m_pArray[i] = this->m_pArray[i + 1];
	this->m_numElements--;
}

//Triggers the Recursive Binary search function, but is not the recursive function itself
template <typename T>
int OrderedArray<T>::Search(T item)
{
	if (this->m_numElements == 0) {
		cout << "This Array is empty" << endl;
		return -1;
	}
	return BinarySearch(0, this->m_numElements - 1, item);
}

//returns the type of array this object is
template <typename T>
string OrderedArray<T>::GetArrayType()
{
	return "Ordered Array";
}

//sets the flag that allows duplicates in the array with Add
template <typename T>
void OrderedArray<T>::SetAllowDuplicates(bool allow)
{
	m_allowDuplicates = allow;
}

//gets the flag that indicates if duplcaites are allowed in the array
template <class T>
bool OrderedArray<T>::AllowDuplicates()
{
	return m_allowDuplicates;
}

template <typename T>
bool OrderedArray<T>::CheckForDuplicate(T item)
{
	//if an index other than -1 returned, this value is already in the array
	if (Search(T) > -1)
		return true;
	return false;
}

template <typename T>
int OrderedArray<T>::BinarySearch(int startIndex, int endIndex, T item)
{
	//if the 2 points ever cross, the item is not in the array
	if (startIndex > endIndex)
		return -1;

	//bitwise operator: same as dividing by 2
	int midIndex = (startIndex + endIndex) >> 1;

	//if the midpoint is the item in question, return its index
	if (this->m_pArray[midIndex] == item)
		return midIndex;
	else {
		//Otherwise, check which side of the array the item is most likely to be on
		if (this->m_pArray[midIndex] < item)
			return BinarySearch(startIndex, midIndex - 1, item);
		else
			return BinarySearch(midIndex + 1, endIndex, item);
			
	}

	return -1;
}
