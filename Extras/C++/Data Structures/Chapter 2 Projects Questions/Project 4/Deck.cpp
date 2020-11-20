#include "Deck.h"
#include <iostream>


using namespace std;
using namespace ch2_p4_Leo_H;

deck::deck()
{
	card_index = 0;
}

void deck::set_card(int suit, int rank)
{
	if (card_index > 0)
	{
		bool card_found = false;
		int found_index = 0;
		for (int i = 0; i < card_index; i++)
		{
			if (cards[i][0] == rank && cards[i][1] == suit)
			{
				card_found = true;
				found_index = i;
				break;
			}
		}
		if (card_found)
		{
			for (int i = found_index; i < card_index; i++)
			{
				cards[i][0] = cards[i + 1][0];
				cards[i][1] = cards[i + 1][1];
			}
			card_index--;
			cout << "Card Removed" << endl;
		}
		else
		{
			cout << "You don't have this card." << endl;
		}
	}
	else
	{
		cout << "You Have no Cards." << endl;
	}
}

void deck::retrieve_card(int suit, int rank)
{

	if (card_index < CAPACITY)
	{
		for (int i = 0; i < card_index; card_index++)
		{
			if (cards[i][0] == rank && cards[i][1] == suit)
			{
				cout << "You have this card already." << endl;
				return;
			}
		}
		switch (rank)
		{
		case 1:
			cout << "Ace of ";
			break;
		case 2:
			cout << "2 of ";
			break;
		case 3:
			cout << "3 of ";
			break;
		case 4:
			cout << "4 of ";
			break;
		case 5:
			cout << "5 of ";
			break;
		case 6:
			cout << "6 of ";
			break;
		case 7:
			cout << "7 of ";
			break;
		case 8:
			cout << "8 of ";
			break;
		case 9:
			cout << "9 of ";
			break;
		case 10:
			cout << "10 of ";
			break;
		case 11:
			cout << "Jack of ";
			break;
		case 12:
			cout << "Queen of ";
			break;
		case 13:
			cout << "King of ";
			break;
		default:
			cout << "Invalid card" << endl;
			return;
		}
		switch (suit)
		{
		case 1:
			cout << "Spades Retrieved" << endl;
			break;
		case 2:
			cout << "Hearts Retrieved" << endl;
			break;
		case 3:
			cout << "Diamonds Retrieved" << endl;
			break;
		case 4:
			cout << "Clubs Retrieved" << endl;
			break;
		default:
			cout << "Invalid Card" << endl;
		}

		cards[card_index][0] = rank;
		cards[card_index][1] = suit;
		card_index++;
	}
	else
	{
		cout << "You have all of the cards." << endl;
	}
}