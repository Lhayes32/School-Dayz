#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;
int main() {
	int years = 0;
	int s_year = 0;
	int max = 0;
	int m_index = 0;
	int temp = 0;
	cout << "Enter the number of years: ";
	cin >> years;
	cout << "Enter the starting year: ";
	cin >> s_year;
	int top = years;
	int* Array = new int[years];
	int* Array2 = new int[years];
	for (int i = 0; i < years; i++) {
		cout << "Enter stat for year " << s_year + i << ": ";
		cin >> Array[i];
		Array2[i] = s_year + i;
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < top; j++) {
			if (max < Array[j]) {
				max = Array[j];
				m_index = j;

			}
		}
		for (int k = m_index; k < top - 1; k++) {
			temp = Array[k];
			Array[k] = Array[k + 1];
			Array[k + 1] = temp;
			temp = Array2[k];
			Array2[k] = Array2[k + 1];
			Array2[k + 1] = temp;
		}
		max = 0;
		top--;
	}

	for (int i = 0; i < years; i++) {
		cout << Array2[i] << "|";
	}

}