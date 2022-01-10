#ifndef DECK_HPP
#define DECK_HPP

#include <vector>
#include "card.hpp"

class Deck
{

private:
	std::vector<Card> cards;

public:
        static const int numCards = 52;
	static const int numSuit = 4;

	Deck();
	void showDeck();
	void shuffle();
	Card draw(int i);
	
};

#endif
