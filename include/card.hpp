#ifndef CARD_HPP
#define CARD_HPP

#include "suit.hpp"

enum class FaceValue
{
	TWO,   // 0
	THREE, // 1
	FOUR,  // 2
	FIVE,  // 3
	SIX,   // 4
	SEVEN, // 5
	EIGHT, // 6
	NINE,  // 7
	TEN,   // 8
	JACK,  // 9
	QUEEN, // 10
	KING,  // 11
	ACE,   // 12
	LAST
};

class Card
{

private:
	FaceValue value;
	Suit suit;
	std::string faceValueStringSimple[13] = {
		"2",
		"3",
		"4",
		"5",
		"6",
		"7",
		"8",
		"9",
		"10",
		"J",
		"Q",
		"K",
		"A"
	};

public:
	Card();
	Card(FaceValue value, FaceSuit faceSuit);

	void setFaceValue(FaceValue value);
	void setFaceSuit(FaceSuit faceSuit);
	FaceValue getFaceValue();
	FaceSuit getFaceSuit();
	std::string toString();
	std::string toStringFaceValue();
	std::string toStringFaceSuit();
	
};

#endif
