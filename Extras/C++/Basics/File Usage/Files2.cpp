#include <iostream>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;
int main() {
	int* array = new int[15];
	int index = 0;
	int target = 0;
	int mid = 0;
	int left = 0;
	int right = 14;
	string mytext;
	fstream file;
	file.open("input.txt",  fstream::in);
	for (int i = 0; i < 15; i++) {
		file >> array[i];
	}

	cout << "enter a target: ";
	cin >> target;


	for (int i = 0; i < 15; i++) {
		cout << array[i] << "|";
	} 
	cout << endl;
	for (int i = 0; i < 15; i++) {
		cout << i << " ";
		if (target == array[i]) {
			break;
		}
	}


	cout << endl;
	for (int i = 0; i < 15 / 2; i++) {
		mid = left + (right - left) / 2;
		if (left > right) {

			break;
		}
		cout << mid << " ";
		if (target == array[mid]) {

			break;
		}
		else {
			if (array[mid] > target) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
	}
	cout << endl;

	file.close();
}