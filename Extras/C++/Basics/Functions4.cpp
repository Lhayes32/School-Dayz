#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int min(int x, int y, int z) {
	int min = x;
	int array[3] = { x, y, z };
	for (int i = 0; i < 3; i++) {
		if (array[i] < min) {
			min = array[i];
		}
	}
	return min;
}

int max(int x, int y, int z) {
	int max = x;
	int array[3] = { x, y, z };
	for (int i = 0; i < 3; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	return max;
}

double average(int x, int y, int z) {
	double avg = 0;
	int array[3] = { x, y, z };
	for (int i = 0; i < 3; i++) {
		avg += array[i];
	}
	return avg / 3.0;
}

int main() {
	int x, y, z;
	cout << "enter number 1: ";
	cin >> x;
	cout << "enter number 2: ";
	cin >> y;
	cout << "enter number 3: ";
	cin >> z;
	cout << "min is " << min(x, y, z) << endl;
	cout << "max is " << max(x, y, z) << endl;
	cout << "average is " << average(x, y, z);
}