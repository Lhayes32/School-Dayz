#include <iostream>
#include <string>
#include <cstdio>
#include "math.h"

using namespace std;

int ** sort2D(int** arr) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int m = i;
			int n = j + 1;
			while (true) {
				if (n == 3) {
					n = 0;
					m++;
					if (m == 3) break; 
				}

				if (arr[i][j] > arr[m][n]) std::swap(arr[i][j], arr[m][n]);

				n++;
			}
		}
	}
	return arr;
}


int main() {
	int** arr = new int* [3];
	bool same = true;
	for (int i = 0; i < 3; ++i)
	{
		arr[i] = new int[3];
	}
	int** arr2 = new int* [3];
	for (int i = 0; i < 3; ++i)
	{
		arr2[i] = new int[3];
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "Array 1 slot (" << i << ", " << j << "):" ;
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "\t" << arr[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "Array 2 slot (" << i << ", " << j << "):";
			cin >> arr2[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "\t" << arr2[i][j];
		}
		cout << endl;
	}

	arr = sort2D(arr);
	arr2 = sort2D(arr2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "|" << arr[i][j];
		}
	}
	cout << "|" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "|" << arr2[i][j];
		}
	}
	cout << "|" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i][j] != arr2[i][j]) {
				same = false;
				break;
			}
		}
	}

	if (same == true) {
		cout << "Arrays are equivalent.";
	}
	else {
		cout << "Arrays are not equivalent.";
	}

}