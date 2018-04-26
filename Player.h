#ifndef PLAYER_H
#define PLAYER_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

class Player
{

	unsigned int id;
	char name[128];

public:

	Player(unsigned int id = 0, const char name[128] = { '\0' });
	~Player();

	friend std::ostream & operator<<(std::ostream & o, const Player & p);

};

#endif PLAYER_H