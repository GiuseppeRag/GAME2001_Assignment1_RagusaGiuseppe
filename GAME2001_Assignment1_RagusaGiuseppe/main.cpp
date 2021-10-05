#include <iostream>
#include "Array.h"
#include "UnorderedArray.h"

using namespace std;

int main() {
	Array<int>* myArray = new UnorderedArray<int>(2);
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
	myArray->Remove(2);

	delete myArray;

	return 0;
}