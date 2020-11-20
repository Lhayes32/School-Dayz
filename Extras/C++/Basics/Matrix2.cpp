#include <iostream>
#include <string>
#include "math.h"

using namespace std;

int* findMax(int** a) {
	int* info = new int[2];
	int largest = a[0][0];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (a[i][j] > largest) {
				largest = a[i][j];
				info[0] = i;
				info[1] = j;
			}
		}
	}
	return info;
}


int main() {
	int** arr = new int* [3];
	for (int i = 0; i < 3; ++i)
		{
			arr[i] = new int[3];
	}
	int* arr2 = new int[2];
	int row = 0, col = 0, largest;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << "Enter a value: ";
			cin >> arr[i][j];
		}
	}
	largest = arr[0][0];
	cout << "The entered matrix:" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << "\t" << arr[i][j];
		}
		cout << endl;
	}
	arr2 = findMax(arr);
	cout << "First Largest value is located at row " << arr2[0] << " and column " << arr2[1];
}