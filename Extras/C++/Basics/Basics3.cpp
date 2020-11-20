#include <iostream>
using namespace std;

int main() {
	int fn, sn;
	char op;
	cout << "Enter first number: ";
	cin >> fn;
	cout << "Enter second number: ";
	cin >> sn;
	cout << "Enter the operator to apply: ";
	cin >> op;
	switch (op) {
	case '+':
		cout << fn + sn << endl;
		break;
	case '-':
		cout << fn - sn << endl;
		break; 
	case '*':
		cout << fn * sn << endl;
		break; 
	case '/':
		cout << fn / sn << endl;
		break; 
	case '%':
		cout << fn % sn << endl;
		break; 
	default:
		break;
	
	}
}