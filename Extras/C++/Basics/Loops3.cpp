
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;
int main() {
	int size;
	cout << "Enter size of array: ";
	cin >> size;
	int * Array;
	Array = new int[size];
	for (int i = 0; i < size; i++) {
		Array[i] = pow(i, 2);
	}

	for (int i = 0; i < size; i++) {
		cout << "|" << Array[i];
	}

	cout << endl;

}