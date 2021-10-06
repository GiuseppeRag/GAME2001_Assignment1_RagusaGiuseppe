#include <iostream>
#include "Array.h"
#include "UnorderedArray.h"
#include "OrderedArray.h"

using namespace std;

int main() {
	/*Array<int>* myArray = new UnorderedArray<int>(2);
	myArray->Remove(2);
	myArray->Add(5);
	myArray->Add(3);
	cout << myArray->GetMaxSize() << endl;
	myArray->Add(1);
	cout << myArray->GetMaxSize() << endl;
	myArray->Add(2);
	cout << myArray->GetMaxSize() << endl;
	cout << myArray->GetNumElements() << endl;
	myArray->Search(3);
	myArray->Remove(2);*/

	Array<int>* myArray = new OrderedArray<int>(2, false);
	myArray->Remove(3);
	myArray->Add(5);
	myArray->Add(3);
	myArray->Add(7);
	myArray->DisplayValues();
	myArray->Add(6);
	myArray->Add(2);
	myArray->Add(6);
	cout << myArray->GetExpandValue() << endl;
	myArray->DisplayValues();
	myArray->Pop();
	cout << "2 Found at index : " << myArray->Search(2) << endl;
	cout << "7 Found at index : " << myArray->Search(7) << endl;
	myArray->DisplayValues();

	delete myArray;

	return 0;

	/*
		TO DO:
		- Make Clean up Ordered Array's ADD function
		- Put the REMOVE function in the Array class instead of both subclasses
		- Make a SORT function for the Ordered Array using Week 4 lab
		- Fix Ordered array to sort in ASCENDING and then fix BINARY SEARCH to work that way
		- Make a custom ASSERT function
		- Make a Cleaner main.cpp file for examples
		- Final Cleanup
	*/
}