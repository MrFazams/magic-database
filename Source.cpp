#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>
#include <fstream>
#include "Container.h"
#include "Player.h"
#include "Card.h"
#include "Deck.h"

using namespace std;

bool stop = false;
Container<Player> players;
Container<Card> cards;
Container<Deck> decks;

void input();									// Takes user input
void loadData();								// Loads files
void saveData();								// Saves files with changes
void createPlayer(const char * name);			// Generates new player with given name
void createCard(const char * input);			// Generates new card
void createDeck(const char * input);			// Generate new deck
void report();									// 

int main()
{
	loadData();
	while (!stop) {
		input();
	}
	saveData();
	return 0;
}

void input()
{
	char input[256];
	cout << "Enter command: ";
	cin.getline(input, 256);

	if (strstr(input, "exit") == &input[0]) {
		stop = true;
		return;
	}

	else if (strstr(input, "cp") == &input[0]) {
		if (strlen(input) < 4) {
			cout << "Please enter player name!\n";
			return;
		}
		createPlayer(&input[3]);
		return;
	}

	else if (strstr(input, "cc") == &input[0]) {
		if (strlen(input) < 6) {
			cout << "Please enter card name and color!\n";
			return;
		}
		unsigned int counter = 0;
		for (unsigned int i = 0; i < strlen(input); i++) {
			if (input[i] == ' ') counter++;
		}
		if (counter < 2) {
			cout << "Please enter card name and color!\n";
			return;
		}
		createCard(&input[3]);
		return;
	}

	else if (strstr(input, "clear") == &input[0]) {
		system("cls");
		return;
	}

	else if (strstr(input, "report") == &input[0]) {
		report();
		return;
	}

	else {
		cout << "Invalid command! Possible commands: exit, cp, clear, report\n";
		return;
	}
}

void loadData()
{
	ifstream in;

	//	Load player data

	in.open("players.bin", ios::binary);
	if (in.is_open()) {
		unsigned int size;
		in.read((char *)&size, sizeof(unsigned int));
		for (unsigned int i = 0; i < size; i++) {
			Player p;
			in.read((char *)&p, sizeof(Player));
			players.add(p);
		}
	}
	in.close();

	//	Load card data

	in.open("cards.dat", ios::binary);
	if (in.is_open()) {
		unsigned int size;
		in.read((char *)&size, sizeof(unsigned int));
		for (unsigned int i = 0; i < size; i++) {
			Card c;
			in.read((char *)&c, sizeof(Card));
			cards.add(c);
		}
	}
	in.close();

	//	Load deck data

	in.open("decks.dat", ios::binary);
	if (in.is_open()) {
		unsigned int size;
		in.read((char *)&size, sizeof(unsigned int));
		for (unsigned int i = 0; i < size; i++) {
			Deck d;
			in.read((char *)&d, sizeof(Deck));
			decks.add(d);
		}
	}
	in.close();

}

void saveData()
{
	ofstream out;

	//	Save player data

	out.open("players.dat", ios::binary | ios::trunc);
	unsigned int size = players.getSize();
	out.write((char *)&size, sizeof(unsigned int));
	for (unsigned int i = 0; i < size; i++) {
		out.write((char *)&players[i], sizeof(Player));
	}
	out.close();

	//	Save card data

	out.open("cards.dat", ios::binary | ios::trunc);
	size = cards.getSize();
	out.write((char *)&size, sizeof(unsigned int));
	for (unsigned int i = 0; i < size; i++) {
		out.write((char *)&cards[i], sizeof(Card));
	}
	out.close();

	//	Save deck data

	out.open("decks.dat", ios::binary | ios::trunc);
	size = decks.getSize();
	out.write((char *)&size, sizeof(unsigned int));
	for (unsigned int i = 0; i < size; i++) {
		out.write((char *)&decks[i], sizeof(Deck));
	}
	out.close();

}

void createPlayer(const char * name)
{
	Player p(players.getSize(), name);			// getSize returns new ID
	players.add(p);
	cout << "Player " << name << " successfully added!\n";
}

void createCard(const char * input)
{

	//	Split input

	char temp1[64], temp2[64];
	int i = 0;
	while (input[i] != ' ') {
		temp1[i] = input[i];
		++i;
	}
	temp1[i] = '\0';
	++i;
	int j = 0;
	while (input[i] != '\0') {
		temp2[j] = input[i];
		++j;
		++i;
	}
	temp2[j] = '\0';

	//	Specify color

	clr color;
	if (strstr(temp1, "White") != NULL || strstr(temp1, "white") != NULL) {
		color = White;
	}
	else if (strstr(temp1, "Red") != NULL || strstr(temp1, "red") != NULL) {
		color = Red;
	}
	else if (strstr(temp1, "Blue") != NULL || strstr(temp1, "blue") != NULL) {
		color = Blue;
	}
	else if (strstr(temp1, "Green") != NULL || strstr(temp1, "green") != NULL) {
		color = Green;
	}
	else if (strstr(temp1, "Black") != NULL || strstr(temp1, "black") != NULL) {
		color = Black;
	}
	else {
		cout << "Invalid color! Correct syntax is: cc <color> <name>\nPossible colors: Red, White, Blue, Black, Green\n";
		return;
	}

	//	Create card and add to list

	Card c(cards.getSize(), color, temp2);
	cards.add(c);
	cout << "Card " << temp2 << " successfully added!\n";
	
}

void createDeck(const char * input)
{

}

void report() 
{
	for (unsigned int i = 0; i < cards.getSize(); i++) {
		cout << "Card name: " << cards[i].getName() << " ID: " << cards[i].getID() << " Color: ";
		switch (cards[i].getColor()) {
		case Red: cout << "Red\n"; break;
		case White: cout << "White\n"; break;
		case Blue: cout << "Blue\n"; break;
		case Black: cout << "Black\n"; break;
		case Green: cout << "Green\n"; break;
		case NOT_SPECIFIED: cout << "N/A\n"; break;
		}
	}
}