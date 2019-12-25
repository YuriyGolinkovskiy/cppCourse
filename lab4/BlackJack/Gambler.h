#pragma once

#include "Hand.h"
#include "Deck.h"

class Gambler
{
private:
	int money;

	Hand* hand;

	
public:
	Hand* getHand();
	int getmoney();
	void setmoney(int money);
	
	//void split();

	void clear();
	void takeCards(Deck* deck);


	Gambler(int money);
	~Gambler();
};

