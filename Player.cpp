#include "Player.h"



Player::Player(unsigned int id, const char name[128])
{
	this->id = id;
	strcpy(this->name, name);
}


Player::~Player()
{
}

std::ostream & operator<<(std::ostream & o, const Player & p)
{
	return o << p.id << p.name << std::endl;
}
