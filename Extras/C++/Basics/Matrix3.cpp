#include <iostream>
#include <string>
#include <cstdio>
#include "math.h"

using namespace std;


int ** addArrays(int **a, int **b) {
	int ** arr3 = new int*[3];
	for (int i = 0; i < 3; ++i)
	{
		arr3[i] = new int[3];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			arr3[i][j] = a[i][j] + b[i][j];
		}
	}
	return arr3;
}

int main() {
	int** arr = new int* [3];
	for (int i = 0; i < 3; ++i)
	{
		arr[i] = new int[3];
	}
	int** arr2 = new int* [3];
	for (int i = 0; i < 3; ++i)
	{
		arr2[i] = new int[3];
	}
	int** arr3 = new int* [3];
	for (int i = 0; i < 3; ++i)
	{
		arr3[i] = new int[3];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "enter a value a: ";
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "enter a value for b: ";
			cin >> arr2[i][j];
		}
	}
	cout << "Matrix A:" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "\t" << arr[i][j];
		}
		cout << endl;
	}


	cout << "Matrix B:" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "\t" << arr2[i][j];
		}
		cout << endl;
	}

	arr3 = addArrays(arr, arr2);

	cout << "A + B:" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "\t" << arr3[i][j];
		}
		cout << endl;
	}


}