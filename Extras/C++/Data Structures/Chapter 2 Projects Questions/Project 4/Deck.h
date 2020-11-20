#ifndef DECK_H
#define DECK_H

namespace ch2_p4_Leo_H
{
	class deck {
	public:
		static const int CAPACITY = 52;
		deck();
		void set_card(int suit, int rank);
		void retrieve_card(int suit, int rank);
	private:
		int cards[CAPACITY][2];
		int card_index;
	};
}


#endif