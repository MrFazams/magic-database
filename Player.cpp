#include "Player.h"



Player::Player(unsigned int id, const char * name)
{
	setID(id);
	setName(name);
}

Player::~Player()
{
}

unsigned int Player::getID() const
{
	return this->id;
}

const char * Player::getName() const
{
	return this->name;
}

void Player::setID(unsigned int id)
{
	this->id = id;
}

void Player::setName(const char * name)
{
	if (name == NULL) {
		this->name[0] = '\0';
		return;
	}
	int i = 0;
	while (name[i] != '\0' && i < 128) {
		this->name[i] = name[i];
		++i;
	}
	this->name[i] = '\0';
}
