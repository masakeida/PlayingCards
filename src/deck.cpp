#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include "suit.hpp"
#include "card.hpp"
#include "deck.hpp"

#define GENERATE_ENUM_ITERATOR(T) \
inline T operator++(T& x) { return x = (T)(std::underlying_type<T>::type(x) + 1); } \
inline T operator*(T c) { return c; } \
inline T begin(T r) { return static_cast<T>(0); } \
inline T end(T r) { T l = T::LAST; return l; }

GENERATE_ENUM_ITERATOR(FaceSuit);
GENERATE_ENUM_ITERATOR(FaceValue);

Deck::Deck()
{
	int i = 0;
	for (FaceSuit s : FaceSuit()) {
		for (FaceValue v : FaceValue()) {
			Card newCard;
			newCard.setFaceSuit(s);
			newCard.setFaceValue(v);
			this->cards.emplace_back(newCard);
			i++;
			if (i >= this->numCards) {
				break;
			}
		}
		if (i >= this->numCards) {
			break;
		}
	}
	
}

void Deck::showDeck()
{
	for (int i = 0; i < this->numCards; i++) {
		std::cout << this->cards[i].toString();
		std::cout << " ";
	}
	std::cout << std::endl;
}

void Deck::shuffle()
{
	std::random_device seed_gen;
	std::mt19937 engine(seed_gen());
	std::shuffle(this->cards.begin(), this->cards.end(), engine);
}

Card Deck::draw(int i)
{
	if (i >= this->numCards) {
		/* error */
		std::cerr << "error: no card number. return 7 of Joker" << std::endl;
		Card error;
		return error;
	}
	return this->cards[i];
}
