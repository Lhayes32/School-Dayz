#include <iostream>
#include <string>
#include "math.h"

using namespace std;

int columnTotal(int* i) {
	int sum = 0;
	for (int j = 0; j < 3; j++) {
		sum += i[j];
	}
	return sum;
}

int rowTotal(int* i) {
	int sum = 0;
	for (int j = 0; j < 4; j++) {
		sum += i[j];
	}
	return sum;
}

int main() {
	int** arr = new int* [3];
	for (int i = 0; i < 3; ++i)
		{
			arr[i] = new int[3];
	}
	int* column = new int[3];
	int row = 0, col = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << "Enter a value: ";
			cin >> arr[i][j];
		}
	}
	cout << "The entered matrix:" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << "\t" << arr[i][j];
		}
		cout << endl;
	}

	for (int j = 0; j < 4; j++)  {
		for (int i = 0; i < 3; i++) {
			column[i] = arr[i][j];
		}
		cout << "Sum of column " << j << " is " << columnTotal(column) << endl;
	}

	for (int i = 0; i < 3; i++) {
		cout << "Sum of row " << i << " is " << rowTotal(arr[i]) << endl;
	}

}