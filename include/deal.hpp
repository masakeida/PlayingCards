#ifndef DEAL_HPP
#define DEAL_HPP

#include <vector>

class Deal
{

private:
	static const int cardListMinLength = 8;
	static const int cardListMaxLength = 16;
	std::vector<std::vector<Card>> hands;
	std::vector<std::vector<Card>> sortedHands;

	std::vector<Card> sortCards(std::vector<Card>);
	void displayHandsByPlayerNS(int i);
	void displayHandsByPlayerEW(int i, int h);
	std::string cardListByPlayerSuit(int i, int j);

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
