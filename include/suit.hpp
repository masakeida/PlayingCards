#ifndef SUIT_HPP
#define SUIT_HPP

enum class FaceSuit
{
	CLUB,
	DIAMOND,
	HART,
	SPADE,
	JOKER,
	LAST
};

class Suit
{

private:
	FaceSuit value;
	std::string faceSuitStringSimple[5] = { "C", "D", "H", "S", "Jo" };
	std::string faceSuitString[5] = {
		"Clubs",
		"Diamonds",
		"Harts",
		"Spades",
		"Jokers"
	};

public:
	Suit();
	Suit(FaceSuit value);

	void setSuit(FaceSuit value);
	FaceSuit getSuit();
	std::string toString();

};

#endif
