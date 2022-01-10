#include <algorithm>
#include <iostream>
#include <string>
#include "suit.hpp"
#include "card.hpp"
#include "deck.hpp"
#include "deal.hpp"

Deal::Deal()
{	
	this->hands.resize(Deal::numPlayers);
	for (int i = 0; i < numPlayers; i++) {
		this->hands[i].resize(numHands);
	}

	this->sortedHands.resize(Deal::numPlayers);
	for (int i = 0; i < numPlayers; i++) {
		this->sortedHands[i].resize(numHands);
	}
}

void Deal::dealHands(Deck deck)
{
	int i = 0;
	while (i < Deck::numCards) {
		for (int j = 0; j < Deal::numHands; j++) {
			for (int k = 0; k < Deal::numPlayers; k++) {
				this->hands[k][j] = deck.draw(i);
				i++;
			}
		}
	}
}

void Deal::sortHands()
{
	for (int i = 0; i < Deal::numPlayers; i++) {
		std::vector<Card> hand;
		for (int j = Deck::numSuit - 1; j > -1; j--) { /* from Spades to Clubs */
			std::vector<Card> cardsSuit;
			std::vector<Card> returnCardsSuit;
			for (int k = 0; k < Deal::numHands; k++) {
				int s = static_cast<int>(this->hands[i][k].getFaceSuit());
				if (j == s) {
					cardsSuit.emplace_back(this->hands[i][k]);
				}
			}
			if (cardsSuit.size() != 0) {
				returnCardsSuit = this->sortCards(cardsSuit);
				for (int k = 0; k < returnCardsSuit.size(); k++) {
					hand.emplace_back(returnCardsSuit[k]);
				}
			}
		}

		if (hand.size() != Deal::numHands) {
			/* error */
			std::cerr << "error: numHands not match!" << std::endl;
		} else {
			for (int j = 0; j < Deal::numHands; j++) {
				this->sortedHands[i][j] = hand[j];
			}
		}
	}
}

std::vector<Card> Deal::sortCards(std::vector<Card> inputCards)
{
	std::vector<Card> outputCards;
	std::vector<int> output;
	int thisSuit = 0;

	if (inputCards.size() == 0) {
		return outputCards;
	}
	
	for (int i = 0; i < inputCards.size(); i++) {
		if (i == 0) {
			thisSuit = static_cast<int>(inputCards[i].getFaceSuit());
		}
		int suitValue = static_cast<int>(inputCards[i].getFaceSuit());
		if (thisSuit != suitValue) {
			/* error */
			std::cerr << "error: inputCards has multiple suit." << std::endl;
			return outputCards;
		}
	}
	
	for (int i = 0; i < inputCards.size(); i++) {
		output.emplace_back(static_cast<int>(inputCards[i].getFaceValue()));
	}
	
	std::sort(output.begin(), output.end(), std::greater<int>());

	for (int i = 0; i < output.size(); i++) {
		Card nextCard;
		nextCard.setFaceSuit(static_cast<FaceSuit>(thisSuit));
		nextCard.setFaceValue(static_cast<FaceValue>(output[i]));
		outputCards.emplace_back(nextCard);
	}

	return outputCards;
}

void Deal::showHands()
{
	for (int i = 0; i < Deal::numPlayers; i++) {
		for (int j = 0; j < Deal::numHands; j++) {
			std::cout << this->hands[i][j].toString();
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

void Deal::displayHands()
{
	for (int i = 0; i < Deal::numPlayers; i++) {
		for (int j = Deck::numSuit - 1; j > -1; j--) { /* from Spades to Clubs */
			std::vector<Card> cardsSuit;
			std::string cardsListBySuit;
			Card suitCard;
			suitCard.setFaceSuit(static_cast<FaceSuit>(j));
			for (int k = 0; k < Deal::numHands; k++) {
				int s = static_cast<int>(this->sortedHands[i][k].getFaceSuit());
				if (j == s) {
					cardsSuit.emplace_back(this->sortedHands[i][k]);
				}
			}
			cardsListBySuit += suitCard.toStringFaceSuit();
			cardsListBySuit += ": ";
			if (cardsSuit.size() != 0) {
				for (int k = 0; k < cardsSuit.size(); k++) {
					cardsListBySuit += cardsSuit[k].toStringFaceValue();
					cardsListBySuit += " ";
				}
			}
			std::cout << cardsListBySuit << std::endl;
		}
		std::cout << std::endl;
	}
}
