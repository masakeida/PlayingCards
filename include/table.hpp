#ifndef TABLE_HPP
#define TABLE_HPP

#include <vector>
#include "deck.hpp"
#include "deal.hpp"

class Table
{
private:
	// std::vector<Player> players;
	Deck deck;
	std::vector<Deal> deals;

public:
	Table();
	void makeDeal(int i);
	void displayHands(int i);
	
};

#endif
