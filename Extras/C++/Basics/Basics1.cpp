/*
Class: CSE 1321L
Section: 16
Term: Fall 2020
Instructor: Vishal Bilagi
Name: Jeremiah Hayes
Lab#:J264
*/
// Lab3C
#include <iostream>
using namespace std;

//BEGIN MAIN
int main() {

	//CREATE guest1, guest2
	string guest1, guest2;

	//PRINT "Enter guest 1: "
	cout << "Enter guest 1: ";

	//READ guest1
	cin >> guest1;

	//PRINT "Enter guest 2: "
	cout << "Enter guest 2: ";

	//READ guest2
	cin >> guest2;

	//IF(guest1 == "Taylor" && guest2 == "Fernando") THEN
	if (guest1 == "Taylor" && guest2 == "Fernando") {

		//PRINTLN "Your party is ruined and another bad pop song will be written."
		cout << "Your party is ruined and another bad pop song will be written." << endl;
	}

	//ELSE IF(guest1 == "Fernando" && guest2 == "Taylor") THEN
	else if (guest1 == "Fernando" && guest2 == "Taylor") {
		//PRINTLN "Your party is ruined and another bad pop song will be written."
		cout << "Your party is ruined and another bad pop song will be written." << endl;
	}

	//ELSE
	else {
		//PRINTLN "Your party was a hit!"
		cout << "Your party was a hit!" << endl;
	}

}

//END MAIN


