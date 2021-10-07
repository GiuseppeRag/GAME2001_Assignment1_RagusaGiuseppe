#pragma once
#include "Array.h"

template <typename T>
class OrderedArray : public Array<T>
{
public:
	OrderedArray(int startSize, bool allowDupes);
	~OrderedArray() override;

	void Push(T item) override;
	int Search(T item) override;
	string GetArrayType() override;

	void Sort();
	void SetAllowDuplicates(bool allow);
	bool AllowDuplicates();
private:
	bool m_allowDuplicates;

	bool CheckForDuplicate(T item);
	int BinarySearch(int startIndex, int endIndex, T item);
};

//Constructor. Uses an additional boolean for allowing duplicates
template <typename T>
OrderedArray<T>::OrderedArray(int startSize, bool allowDupes) : Array<T>(startSize) {
	m_allowDuplicates = allowDupes;
}

//Destructor
template <typename T>
OrderedArray<T>::~OrderedArray() {}

//Push function
template <typename T>
void OrderedArray<T>::Push(T item)
{
	//Assert to make sure duplicates aren't allowed
	if (!this->Assert(m_allowDuplicates || (!m_allowDuplicates && Search(item) == -1), "Duplicates are not allowed in this Array!"))
		return;

	//Parent function that performs Expanding if Array is full
	this->CheckSize();

	int key;

	//finds the spot in the array where value can be stored
	for (int i = 0; i <= this->m_numElements; i++) {
		key = i;
		if (this->m_pArray[i] == 0 || item < this->m_pArray[i])
			break;
	}

	//shifts every other element down to make room
	for (int j = this->m_numElements; j > key; j--) {
		this->m_pArray[j] = this->m_pArray[j - 1];
	}

	this->m_numElements++;
	this->m_pArray[key] = item;
	cout << "Successfully added new value: " << item << endl;
}

//Triggers the Recursive Binary search function, but is not the recursive function itself
template <typename T>
int OrderedArray<T>::Search(T item)
{
	if (this->m_numElements > 0)
		return BinarySearch(0, this->m_numElements - 1, item);

	return -1;
}

//returns the type of array this object is
template <typename T>
string OrderedArray<T>::GetArrayType()
{
	return "Ordered Array";
}

//Sorts the array (In case it wasn't in proper order)
template <typename T>
void OrderedArray<T>::Sort()
{
	//assert
	if (!this->Assert(this->m_numElements > 0, "Cannot sort because array is empty"))
		return;
	
	//SELECTION SORT
	int smallestItemIndex;
	T temp;

	for (int i = 0; i < this->m_numElements; i++) {
		smallestItemIndex = i;

		for (int j = 1 + i; j < this->m_numElements; j++) {
			if (this->m_pArray[smallestItemIndex] > this->m_pArray[j])
				smallestItemIndex = j;
		}

		//Swapping
		temp = this->m_pArray[smallestItemIndex];
		this->m_pArray[smallestItemIndex] = this->m_pArray[i];
		this->m_pArray[i] = temp;
	}
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

//The recursive function being called for the Search() function
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
		if (this->m_pArray[midIndex] > item)
			return BinarySearch(startIndex, midIndex - 1, item);
		else
			return BinarySearch(midIndex + 1, endIndex, item);
			
	}

	return -1;
}
