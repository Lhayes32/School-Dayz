#include <iostream>
#include <string>
#include <locale>
#include <math.h>

using namespace std;

void codedMessage(string decoded) {
	string encoded;
	for (int i = 0; i < decoded.length(); i++) {
		switch (decoded[i]) {
		case 'a':
			encoded.push_back('4');
			break;
		case 'b':
			encoded.push_back('B');
			break;
		case 'c':
			encoded.push_back('(');
			break;
		case 'd':
			encoded.push_back('D');
			break;
		case 'e':
			encoded.push_back('3');
			break;
		case 'f':
			encoded+="Ph";
			break;
		case 'g':
			encoded.push_back('9');
			break;
		case 'h':
			encoded += "|-|";
			break;
		case 'i':
			encoded.push_back('1');
			break;
		case 'j':
			encoded.push_back('j');
			break;
		case 'k':
			encoded += "|<";
			break;
		case 'l':
			encoded.push_back('L');
			break;
		case 'm':
			encoded += "/\\\\/\\\\";
			break;
		case 'n':
			encoded+="|\\\\|";
			break;
		case 'o':
			encoded.push_back('0');
			break;
		case 'p':
			encoded.push_back('P');
			break;
		case 'q':
			encoded.push_back('Q');
			break;
		case 'r':
			encoded.push_back('R');
			break;
		case 's':
			encoded.push_back('$');
			break;
		case 't':
			encoded.push_back('7');
			break;
		case 'u':
			encoded.push_back('U');
			break;
		case 'v':
			encoded+="\\/";
			break;
		case 'w':
			encoded+= "\\\\/\\\\/";
			break;
		case 'x':
			encoded+= "><";
			break;
		case 'y':
			encoded+= "\'/";
			break;
		case 'z':
			encoded.push_back('Z');
			break;
		default:
			encoded.push_back(decoded[i]);
			break;
		}
	}
	cout << encoded;
}

int main() {
	string decoded;
	cout << "Enter a string: ";
	getline(std::cin, decoded);
	codedMessage(decoded);
}