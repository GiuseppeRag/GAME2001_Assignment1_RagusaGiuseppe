#include <iostream>
#include "Array.h"
#include "UnorderedArray.h"
#include "OrderedArray.h"

using namespace std;

int main() {

	//Example 1
	cout << "===== EXAMPLE 1: Unordered String Array =====" << endl;
	Array<string>* stringArray = new UnorderedArray<string>(2);
	stringArray->Push("Bananas");
	stringArray->Push("Juice");
	stringArray->Push("Spaghetti");
	stringArray->Push("Cheese");
	stringArray->DisplayValues();
	cout << endl << "Array's Max Size: " << stringArray->GetMaxSize() << endl;
	cout << "Number of Elements: " << stringArray->GetNumElements() << endl;
	stringArray->Pop();
	cout << "Pineapples found at index: " <<stringArray->Search("Pineapples") << " (NOT FOUND)" << endl;
	cout << "Juice found index: " << stringArray->Search("Juice") << endl;
	stringArray->Remove(1);
	cout << endl;
	stringArray->DisplayValues();
	delete stringArray;

	//Example 2
	cout << endl << endl << "===== EXAMPLE 2: Ordered Int Array, no duplicates =====" << endl;
	Array<int>* intArray = new OrderedArray<int>(2, false);
	cout << "Expand Value before pushing: " << intArray->GetExpandValue() << endl;
	cout << "Max Size before pushing: " << intArray->GetMaxSize() << endl;
	intArray->Push(4);
	intArray->Push(8);
	intArray->Push(3);
	intArray->Push(2);
	intArray->Push(7);
	cout << "Expand Value after pushing: " << intArray->GetExpandValue() << endl;
	cout << "Max Size after pushing: " << intArray->GetMaxSize() << endl;
	intArray->DisplayValues();

	cout << endl << "Trying to Push another 8:" << endl;
	intArray->Push(8);
	cout << "8 is located at index: " << intArray->Search(8) << endl;
	intArray->Remove(intArray->Search(8));
	intArray->DisplayValues();
	intArray->Push(8);
	intArray->DisplayValues();
	cout << endl;
	delete intArray;

	//Example 3
	cout << endl << endl << "===== EXAMPLE 3: Ordered Float Array. Array modified then sorted =====" << endl;
	OrderedArray<float> floatArray = OrderedArray<float>(3, true);
	floatArray.Push(2.0f);
	floatArray.Push(4.7f);
	floatArray.Push(9.3f);
	floatArray.Push(10.0f);
	floatArray.Push(12.0f);
	floatArray.DisplayValues();
	cout << endl;
	floatArray[3] = 4.7f;
	floatArray[4] = 6.1f;
	cout << "After modifying array: " << endl;
	floatArray.DisplayValues();
	cout << "fixing the array using Sort() function:" << endl;
	floatArray.Sort();
	floatArray.DisplayValues();
	
	cout << endl;
	floatArray.Clear();
	floatArray.DisplayValues();

	return 0;
}