#pragma once

template <class T>
class Array
{
public:
	//Array constructor. Both Subclasses will use this constructor
	Array(int startSize = 5) : m_expandValue(1), m_numElements(0) {
		if (startSize > 0) {
			m_maxSize = startSize;
			m_pArray = new T[startSize];
		}
	}

	//Array destructor. Both subclasses will use this.
	~Array() {
		if (m_pArray != nullptr) {
			delete[] m_pArray;
			m_pArray = nullptr;
		}
	}

	void Clear() {
		if (m_numElements > 0)
			m_numElements = 0;
	}

	//Add item in question to the array. Subclasses have different ways of handling adding
	virtual void Add(T item);

	//Remove an item from the array. Subclasses have different ways of handling removing
	virtual void Remove(int index);

	//Find an item in  the array. Subclasses have different ways of handling search
	virtual void Search(T item);

	//get the Max Size of the array
	int GetMaxSize() {
		return m_maxSize;
	}

	//get the value that the array expands by when the array is full
	int GetExpandValue() {
		return m_expandValue;
	}

	//get the number of elements currently in the array
	int GetNumElements() {
		return m_numElements;
	}

	//Get the type of array (Unordered / Ordered)
	virtual string GetArrayType();
private:
	T* m_pArray;

	int m_maxSize;
	int m_expandValue;
	int m_numElements;
};

