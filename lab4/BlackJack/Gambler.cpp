#include "Gambler.h"
#include "Deck.h"

Gambler::Gambler(int money) : money(money)
{
	hand = new Hand;
}

Gambler::~Gambler()
{ 
	delete hand;
}

int Gambler::getmoney()
{
	return money;
}


void Gambler::setmoney(int money)
{
	this->money = money;
}


void Gambler::clear()
{
		hand->clear();
}

void Gambler::takeCards(Deck* deck)
{
	//FIX
		hand->takeCard(deck);
}

Hand* Gambler::getHand()
{
	return hand;
}