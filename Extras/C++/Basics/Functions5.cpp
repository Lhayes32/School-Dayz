#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

void printArray(int  arr[]) {
	for (int i = 0; i < 10; i++) {
		cout << "|" << arr[i];
	}
}

void  initArray(int arr[]) {
	for (int i = 0; i < 10; i++) {
		arr[i] = 0;
	}
}

void printSum(int arr[]) {
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += arr[i];
	}
	cout << sum;
}

void enterNum(int arr[]) {
	int slot, value;
	cout << "Enter the slot : ";
	cin >> slot;
	cout << "Enter the new value: ";
	cin >> value;
	arr[slot] = value;
}

bool printMenu(int arr[]) {
	bool quit = false;
	int choice = 0;
	cout << "Would you like to: \n 1) Enter a number \n 2) Print the array \n 3) Find the sum of the array \n 4) Reset the array \n 5) Quit \n";
	cin >> choice;
	switch (choice) {
	case 1:
		enterNum(arr);
		break;
	case 2:
		printArray(arr);
		cout << endl;
		break;
	case 3:
		printSum(arr);
		cout << endl;
		break;
	case 4:
		initArray(arr);
		break;
	case 5:
		quit = true;
		break;
	default:
		break;
	}
	return quit;
}

int main() {
	int* Array = new int[10];
	initArray(Array);
	while (!printMenu(Array));

}