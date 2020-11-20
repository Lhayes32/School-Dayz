#include <iostream>
#include <string>
#include <locale>
#include <math.h>

using namespace std;

int main() {
	string input = "";
	locale loc;
	int count = 0;
	cout << "enter a string: ";
	getline(cin, input);
	
	for (int i = 0; i < input.length(); i++) {
		if (toupper(input[i], loc) == 'A' || toupper(input[i], loc) == 'E' || toupper(input[i], loc) == 'I' || toupper(input[i], loc) == 'O' || toupper(input[i], loc) == 'U' || toupper(input[i], loc) == 'U') {
			cout << '*';
			count++;
		}
		else {
			cout << input[i];
		}
	}
	cout << endl;
	cout << "that string has " << count << " vowels.";
	
}