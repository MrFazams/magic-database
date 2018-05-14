#include "Card.h"



Card::Card(unsigned int ID, clr color, const char * name)
{
	setID(ID);
	setColor(color);
	setName(name);
}

Card::Card(const Card & c)
{
	*this = c;
}

Card::~Card()
{
}

unsigned int Card::getID() const
{
	return this->ID;
}

clr Card::getColor() const
{
	return this->color;
}

const char * Card::getName() const
{
	return this->name;
}

void Card::setID(unsigned int ID)
{
	this->ID = ID;
}

void Card::setColor(clr color)
{
	this->color = color;
}

void Card::setName(const char * name)
{
	int i = 0;
	if (name != NULL) {
		while (name[i] != '\0' && i < 64) {
			this->name[i] = name[i];
			++i;
		}
	}
	this->name[i] = '\0';
}

const Card & Card::operator=(const Card & c)
{
	setID(c.getID());
	setColor(c.getColor());
	setName(c.getName());
	return *this;
}
