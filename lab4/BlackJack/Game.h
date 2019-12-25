#pragma once

#include "Gambler.h"
#include "Dealer.h"
#include "Deck.h"
#include "Card.h"

class Game
{
	int cash; 
	int wins = 0;
	bool doubleNow = false;
	//bool tripleNow = false;
	//bool firstStep = false;
	//Кол-во колод
	int countdecks;
	Deck* decks;

	//Участники
	Dealer* dealer;
	Gambler* gambler;


public:
	Game(Dealer* dealer, Gambler* gambler);
	~Game();

	int getChoice();

	void setDecks(Deck* decks, int count);
	void takeCardsDealer();
	void takeCardsGambler();
	void calculateScore();
	void printStatusDeck();
	void printCardsDealer(bool variant);
	void printCardsGambler();
	void printMenu();	
	void dropCards();
	bool init();
	bool checkPerebor();
	//bool isSplit();
	bool isDouble();
	//bool isTriple();
	bool replicateChoice(int choice);
	void PrintCash();
	void DrawInterface();
};

