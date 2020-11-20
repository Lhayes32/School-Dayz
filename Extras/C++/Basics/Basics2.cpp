#include <iostream>
using namespace std;

int main() {
	float people, bill, total, n_tip;
	char tip;

	cout << "How many people in your party? ";
	cin >> people;
	cout << "What is the total cost of your bill? ";
	cin >> bill;

	if (people >= 6) {
		total = bill + (bill * .18);
		cout << "Your bill is $" << total << endl;
		cout << "Would you like to include anadditional tip (Y/N)? ";
		cin >> tip;
		if ('Y' == tip) {
			cout << "How much? ";
			cin >> n_tip;
			cout << "Total bill is: $" << total + n_tip; 
			
		}
	}
	else {
		total = bill;
		cout << "Your bill is $" << total << endl;
		cout << "How much for the tip? ";
		cin >> n_tip;
		cout << "Total bill is: $" << total + n_tip;
	}
}