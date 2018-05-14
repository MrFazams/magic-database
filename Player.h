#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player
{

	unsigned int id;
	char name[128];

public:

	Player(unsigned int id = 0, const char * name = NULL);
	~Player();

	unsigned int getID() const;
	const char * getName() const;

	void setID(unsigned int id);
	void setName(const char * name);

};

#endif PLAYER_H