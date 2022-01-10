#include <string>
#include "deck.hpp"
#include "deal.hpp"
#include "table.hpp"

Table::Table()
{
}

void Table::makeDeal(int i)
{
	Deal nextDeal;
	this->deals.emplace_back(nextDeal);
	this->deck.shuffle();
	this->deals[i].dealHands(this->deck);
	this->deals[i].sortHands();
}

void Table::displayHands(int i)
{
	//this->deals[i].showHands();
	this->deals[i].displayHands();
}
