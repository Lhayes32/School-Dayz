#include <iostream>

using namespace std;

class KoalaBear {
public:
	float weight;

	KoalaBear(float weight) {
		this->weight = weight;
	}
	void eat(float leaves) {
		this->weight += (leaves / 1000.0);
	}
	void showWeight() {
		cout << "This koala weighs " << this->weight << " kilos" << endl;
	}
};
int main() {
	KoalaBear kb(100);
	kb.eat(400);
	kb.showWeight();
	kb.eat(300);
	kb.showWeight();
	kb.eat(650);
	kb.showWeight();
}