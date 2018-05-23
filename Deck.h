#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck
{

	unsigned int ownerID;
	unsigned int cards[60];
	clr color;

public:

	Deck(unsigned int ownerID = 0, unsigned int * cards = { 0 }, clr color = NOT_SPECIFIED);
	~Deck();

	void setOwnerID(unsigned int id);
	void setColor(clr color);
	void addCards(unsigned int * id);

	const unsigned int * getCards() const;

};

#endif DECK_H