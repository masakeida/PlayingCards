#include <string>
#include "suit.hpp"

Suit::Suit()
{
	this->value = FaceSuit::JOKER;
}

Suit::Suit(FaceSuit value)
{
	this->value = value;
}

void
Suit::setSuit(FaceSuit value)
{
	this->value = value;
}

FaceSuit
Suit::getSuit()
{
	return this->value;
}

std::string
Suit::toString()
{
	std::string suitFace;
	suitFace = faceSuitStringSimple[static_cast<int>(this->value)];
	return suitFace;
}
