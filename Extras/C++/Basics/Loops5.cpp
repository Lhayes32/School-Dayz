#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;
int main() {
	int size = 0;
	bool similar = true;
	cout << "Enter size of the arrays: ";
	cin >> size;
	int* Array1 = new int[size];
	int* Array2 = new int[size];

	for (int i = 0; i < size; i++) {
		cout << "Enter array 1 slot " << i << ": ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> Array1[i];
		cout << "Enter array 2 slot " << i << ": ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> Array2[i];
	}

	for (int i = 0; i < size; i++) {
		if (Array1[i] != Array2[i]) {
			similar = false;
		}
	}

	if (similar) {
		cout << "The arrays are identical" << endl;
	}
	else {
		cout << "The arrays are not identical" << endl;
	}
}