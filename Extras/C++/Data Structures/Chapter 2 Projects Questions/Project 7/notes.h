#ifndef NOTES_H
#define NOTES_H
#include <string>

using namespace std;

namespace ch2_p7_Leo_H {
	class notes {
	public:
		notes();
		void set_length(int len);
		void set_note(int note);
		void decipher_note();
		void retrieve_note_info();
	private:
		string note_decipher;
		string length;
		double frequency;
		int current_note;
	};
}


#endif 
