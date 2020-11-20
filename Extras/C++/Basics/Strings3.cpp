#include <iostream>
#include <string>
#include <locale>
#include <math.h>

using namespace std;
int main() {
	string input = "";
	string output = "";
	int asciivalue = 0;
	cout << "enter a string: ";
	getline(cin, input);
	for (int i = 0; i < input.length(); i++) {
		if (input[i] >= 'a' && input[i] <= 'z') {
			asciivalue = (int)input[i];
			asciivalue -= 97;
			asciivalue += 13;
			asciivalue %= 26;
			asciivalue += 97;
			output.push_back((char)asciivalue);
		}
		else {
			output.push_back(input[i]);
		}
	}
	cout << output;

}