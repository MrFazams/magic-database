#include <iostream>
#include <fstream>
#include "Player.h"

using namespace std;

int main()
{
	Player p1(1, "Anna");
	ofstream o("players.txt");
	o << p1;
	system("pause");
	return 0;
}