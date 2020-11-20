
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;
int main() {
	int size = 0;
	int gpa = 0;
	cout << "Enter the number of GPAs: ";
	cin >> size;
	double* Array;
	Array = new double[size];
	for(int i = 0; i < size; i++) {
		cout << "GPA #" << i << ": ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> Array[i];
	}
	for (int i = 0; i < size; i++) {
		if (Array[i] >= 3.9) {
			cout << "Student #" << i << ": Summa Cum Laude"<< endl;
		}
		else if (Array[i] >= 3.7) {
			cout << "Student #" << i << ": Magna Cum Laude" << endl;
		}
		else if (Array[i] >= 3.5) {
			cout << "Student #" << i << ": Cum Laude" << endl;
		}
		else if (Array[i] >= 2) {
			cout << "Student #" << i << ": Graduating" << endl;
		}
		else {
			cout << "Student #" << i << ": Not Graduating" << endl;
		}
	}

}