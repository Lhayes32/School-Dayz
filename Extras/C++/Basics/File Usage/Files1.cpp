#include <iostream>
#include <string.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;
int main() {
	int* Array = new int[10];
	for (int i = 0; i < 10; i++) {
		cout << "Enter slot " << i << ": ";
		cin >> Array[i];
	}
	int max = 0;
	int top = 10;
	int m_index = 0;
	int temp = 0;
	int swaps = 0;
	for (int i = 0; i < top; i++) {
		for (int j = 0; j < top - i - 1; j++) {
			if (Array[j] > Array[j + 1]) {
					temp = Array[j];
					Array[j] = Array[j + 1];
					Array[j + 1] = temp;
					swaps++;
			}
		}
		//cout << max << "," << m_index << endl;
		
		cout << " ";
		for (int l = 0; l < 10; l++) {
			cout << Array[l] << "|" ;
		}
		cout << " Num swaps: " << swaps << endl;
	}



	fstream File;

	File.open("output.csv", fstream::out);
	for (int i = 0; i < 10; i++) {
		File << Array[i] << ",";
	}

	File.close();

}