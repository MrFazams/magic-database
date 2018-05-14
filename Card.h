#ifndef CARD_H
#define CARD_H

#include <iostream>

enum clr { NOT_SPECIFIED, Red, Black, Blue, White, Green };

class Card
{

	unsigned int ID;
	clr color;
	char name[64];

public:

	Card(unsigned int ID = 0, clr color = NOT_SPECIFIED, const char * name = NULL);
	Card(const Card & c);
	~Card();

	unsigned int getID() const;
	clr getColor() const;
	const char * getName() const;

	void setID(unsigned int ID);
	void setColor(clr color);
	void setName(const char * name);

	const Card & operator=(const Card & c);

};

#endif CARD_H