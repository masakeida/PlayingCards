#include <iostream>
#include <string>
#include "table.hpp"

int
main(int argc, char *argv[])
{
	std::string str("This is a hand generator for trick-taking games.");
	std::cout << str << std::endl;
	std::cout << std::endl;

/*	Deck deck;
	deck.showDeck();
	deck.shuffle();
	deck.showDeck();
*/

	Table table;
	table.makeDeal(0);
	table.displayHands(0);
//	table.makeDeal(1);
//	table.displayHands(1);

	return 0;
}
