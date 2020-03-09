// Card Shuffling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <time.h> 
using namespace std;

void shuffle(short[][13]);
void deal(const short[][13], const char *[], const char *[]);
int main()
{
	const char *suite[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	const char *face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",
   "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
	short deck[4][13] = { 0 };

	srand(time(0));
	shuffle(deck);
	deal(deck, face, suite);
	return 0;
}
void shuffle(short wDeck[][13])
{
	short row, column, card;
	for (card = 1; card <= 52; card++) {
		do {
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);
		wDeck[row][column] = card;
	}
}
void deal(const short wDeck[][13], const char *wFace[], const char *wSuit[])
{
	short card, row, column;
	const char *space;
	for (card = 1; card <= 52; card++)
		for (row = 0; row <= 3; row++)
			for (column = 0; column <= 12; column++)
				if (wDeck[row][column] == card)
					cout << card << ". " << wFace[column] << " of " << wSuit
					[row] << '\n';
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
