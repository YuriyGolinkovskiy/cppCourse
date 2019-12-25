#include <locale>
#include <cstdlib>

#include "Deck.h"
#include "Enum.h"
#include "Gambler.h"
#include "Dealer.h"
#include "Game.h"

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL,"Russian");

	int cDecks = 4;
	Deck decks[4];

	decks[0].initDeck(TypeDeck::Full);
	decks[1].initDeck(TypeDeck::Full);
	decks[2].initDeck(TypeDeck::Full);
	decks[3].initDeck(TypeDeck::Full);

	Gambler* gambler = new Gambler(5000);
	Dealer* dealer = new Dealer();

	Game game(dealer, gambler);
	game.setDecks(decks, cDecks);

	while (game.init())
	{
		game.takeCardsDealer();
		game.takeCardsGambler();
		do
		{
			system("cls");
			game.DrawInterface();
			game.printMenu();
		} 
		while (game.replicateChoice(game.getChoice()));

		game.dropCards();
	}

	delete gambler;
	delete dealer;

	system("pause");
	return 0;
}