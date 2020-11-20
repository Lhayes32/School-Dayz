#include <iostream>
#include <string>
#include <locale>
#include <math.h>

using namespace std;
void rgb(int red, int green, int blue) {
	float n_red = red / 255.0;
	float n_green = green / 255.0;
	float n_blue = blue / 255.0;
	cout << "New color is red = " << n_red << " green = " << n_green << " blue = " << n_blue;
}

int main() {
	int red, green, blue;
	cout << "Enter a red value(0 - 255) : ";
	cin >> red;
	cout << "Enter a green value(0 - 255) : ";
	cin >> green;
	cout << "Enter a blue value(0 - 255) : ";
	cin >> blue;
	rgb(red, green, blue);
}