#include "Deck.h"




Deck::Deck(unsigned int ownerID, unsigned int * cards, clr color)
{
	setOwnerID(ownerID);
	addCards(cards);
	setColor(color);
}

Deck::~Deck()
{
}

void Deck::setOwnerID(unsigned int id)
{
	this->ownerID = id;
}

void Deck::setColor(clr color)
{
	this->color = color;
}

void Deck::addCards(unsigned int * id)
{
	for (unsigned int i = 0; i < 60; i++) {
		cards[i] = id[i];
	}
}

const unsigned int * Deck::getCards() const
{
	return cards;
}
