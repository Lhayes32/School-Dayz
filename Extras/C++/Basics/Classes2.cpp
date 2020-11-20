#include <iostream>

using namespace std;

class Turtle {
public:
	int speed;
	string color;

	Turtle() {
		speed = 0;
		color = "green";
	}
	Turtle(int speed, string color) {
		this->speed = speed;
		this->color = color;
	}
};
int main() {
	Turtle t1;
	Turtle t2(5, "purple");
	cout << t1.speed << "\n" << t2.color;
}