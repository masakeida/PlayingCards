#include <string>
#include "card.hpp"

Card::Card()
{
	this->value = FaceValue::SEVEN;
}

Card::Card(FaceValue value, FaceSuit faceSuit)
{
	this->value = value;
	this->setFaceSuit(faceSuit);
}

void Card::setFaceValue(FaceValue value)
{
	this->value = value;
}

void Card::setFaceSuit(FaceSuit faceSuit)
{
	this->suit.setSuit(faceSuit);
}

FaceValue Card::getFaceValue()
{
	return this->value;
}

FaceSuit Card::getFaceSuit()
{
	return this->suit.getSuit();
}

std::string Card::toString()
{
	std::string cardFace;
	cardFace = this->suit.toString();
	cardFace = cardFace
		+ faceValueStringSimple[static_cast<int>(this->value)];
	return cardFace;
}

std::string Card::toStringFaceValue()
{
	std::string cardFaceValue;
	cardFaceValue = faceValueStringSimple[static_cast<int>(this->value)];
	return cardFaceValue;
}

std::string Card::toStringFaceSuit()
{
	std::string cardFaceSuit;
	cardFaceSuit = this->suit.toString();
	return cardFaceSuit;
}
