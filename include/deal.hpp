#ifndef DEAL_HPP
#define DEAL_HPP

#include <vector>

class Deal
{

private:
	std::vector<std::vector<Card>> hands;
	std::vector<std::vector<Card>> sortedHands;

	std::vector<Card> sortCards(std::vector<Card>);

public:
	static const int numPlayers = 4;
        static const int numHands = 13;

	Deal();
	void dealHands(Deck deck);
	void sortHands();
	void showHands();
	void displayHands();
	
};

#endif
