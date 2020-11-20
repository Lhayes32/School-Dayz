#include "notes.h"
#include <string>
#include <iostream>
#include <math.h>

using namespace std;
namespace ch2_p7_Leo_H {
	notes::notes() {
		current_note = -9;
		length = "Quarter Note";
		note_decipher = "C Natural Quarter Note with a frequency of 261.63";
	}
	void notes::set_length(int len)
	{
		switch (len)
		{
		case 1:
			length = "Whole Note";
			break;
		case 2:
			length = "Half Note";
			break;
		case 4:
			length = "Quarter Note";
			break;
		case 8:
			length = "Eighth Note";
			break;
		case 16:
			length = "Sixteenth Note";
			break;
		default:
			cout << "Length not valid";
			break;
		}
	}
	void notes::set_note(int note)
	{
		current_note = note;
		frequency = 440.00 * pow(2.0, (note / 12.0));
		decipher_note();
	}
	void notes::decipher_note()
	{
		switch (current_note) {
		case 1:
			note_decipher = "A Sharp";
			break;
		case 2:
			note_decipher = "B Natrual";
			break;
		case 0:
			note_decipher = "A Natural";
			break;
		case -1:
			note_decipher = "G Sharp";
			break;
		case -2:
			note_decipher = "G Natural";
			break;
		case -3:
			note_decipher = "F Sharp";
			break;
		case -4:
			note_decipher = "F Natural";
			break;
		case -5:
			note_decipher = "E Natural";
			break;
		case -6:
			note_decipher = "D Sharp";
			break;
		case -7:
			note_decipher = "D Natural";
			break;
		case -8:
			note_decipher = "C Sharp";
			break;
		case -9:
			note_decipher = "C Natural";
			break;
		default:
			cout << "Note Invalid" << endl;
			return;
			break;
		}
		note_decipher = note_decipher + " " + length;
		note_decipher = note_decipher + " with a frequency of " + to_string(frequency);
		
	}
	void notes::retrieve_note_info()
	{
		cout << note_decipher << endl;
	}
}