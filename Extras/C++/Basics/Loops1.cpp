#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;
int main() {
	int years = 0;
	int s_year = 0;
	int best = 0;
	int best_y = 0;
	int worst = 0;
	int worst_y = 0;
	cout << "Enter the number of years: ";
	cin >> years;
	cout << "Enter the starting year: ";
	cin >> s_year;
	int* Array = new int[years];
	for (int i = 0; i < years; i++) {
		cout << "Enter stat for year " << s_year + i << ": ";
		cin >> Array[i];
	}

	for (int i = 0; i < years; i++) {
		if ( best < Array[i]) {
			best = Array[i];
			best_y = s_year + i;
			worst = Array[i];
		}
	}

	for (int i = 0; i < years; i++) {
		if (worst > Array[i]) {
			worst = Array[i];
			worst_y = s_year + i;
		}
	}

	cout << "Best stat was " << best << " in year " << best_y << endl;
	cout << "Worst stat was " << worst << " in year " << worst_y << endl;


}