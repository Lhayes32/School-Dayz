#include <iostream>

using namespace std;

class Hero {
public:
	int life;
	bool alive = true;
	Hero(int life) {
		this->life = life;
	}
	void takeDamage(int damage) {
		life -= damage;
		if (life <= 0) {
			alive = false;
		}
	}
};

class Enemy {
public:
	int life;
	bool alive = true;
	Enemy(){}
	Enemy(int life) {
		this->life = life;
	}
	void takeDamage(int damage) {
		life -= damage;
		if (life <= 0) {
			alive = false;
		}
	}
};

static int enemiesAlive(Enemy e[], int size) {
	for (int i = 0; i < size; i++) {
		if (e[i].alive == true) {
			return i;
		}
	}
	return -1;
}

int main() {
	int n_enemies, e_dam, h_hp, h_dam, e_dead = 0, round = 1;
	cout << "Enter the number of enemies: ";
	cin >> n_enemies;
	cout << "Enter the enemy damage: ";
	cin >> e_dam;
	cout << "Enter the hero's starting HP: ";
	cin >> h_hp;
	cout << "Enter the hero's damage: ";
	cin >> h_dam;
	Enemy* e = new Enemy[n_enemies];
	Hero h(h_hp);
	for (int i = 0; i < n_enemies; i++) {
		e[i] = Enemy(10 + (2 * i));
	}

	do {
		for (int i = e_dead; i < n_enemies; i++) {
			e[i].takeDamage(h_dam);
		}
		h.takeDamage(e_dam * (n_enemies - e_dead));
		cout << "==== After round " << round <<  " ====" << endl;
		e_dead = enemiesAlive(e, n_enemies);
		cout << "Num enemies left: " << (e_dead == -1 ? (0) : (n_enemies - e_dead)) << endl;
		for (int i = 0; i < n_enemies; i++) {
			cout << '|' << e[i].life;
		}
		cout << endl;
		cout << "Hero HP: " << h.life << endl;
		round += 1;
	} while ((e_dead != -1) && (h.alive == true));
	if (h.alive == false) {
		cout << "Enemies win!";
	}
	else {
		cout << "Hero wins!!";
	}



}