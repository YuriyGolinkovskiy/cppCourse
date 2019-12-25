
#include <iostream>

#include "Game.h"
#include "Gambler.h"
#include "Dealer.h"


Game::Game(Dealer* dealer, Gambler* gambler) : dealer(dealer), gambler(gambler) { }
Game::~Game() { }

void Game::setDecks(Deck* decks, int count)
{
	this->decks = decks;
	countdecks = count;
}

bool Game::init()
{
	if (0 >= gambler->getmoney())
	{
		std::cout << "\nУ вас нет денег!!!";
	}

	int tmp_money;
	std::cout << "Ваш счет: " << gambler->getmoney() << std::endl;
	std::cout << "\nВаша ставка: ";
	std::cin >> tmp_money;

	if (tmp_money <= 0)
	{
		std::cout << "\nВаша ставка не может быть меньше или равна 0";
		return false;
	}

	if (tmp_money <= gambler->getmoney())
	{
		cash = tmp_money;
		return true;
	}
	else
	{
		std::cout << "\nНехватает денег для ставки";
		return false;
	}	
}

void Game::printStatusDeck()
{
	std::cout << "\nКолоды: "; 
	for (int i = 0; i < countdecks; i++)
	{	
		std::cout << "[" << decks[i].getCountCards() - decks[i].getNumberCard() << "] ";
	}
}

void Game::printCardsDealer(bool isVisible)
{
		std::cout << "\nДилер: ";

		for (int i = 0; i < dealer->getHand()->getcountcards(); i++)
		{
			std::cout << dealer->getHand()->getCards()[i];
		}
}

void Game::printCardsGambler()
{
		std::cout << "\nВаша  рука : ";
		for (int i = 0; i < gambler->getHand()->getcountcards(); i++)
		{
			std::cout << gambler->getHand()->getCards()[i];
		}
		std::cout << std::endl;
}

void Game::takeCardsDealer()
{
	dealer->getHand()->takeCard(decks);
}

void Game::takeCardsGambler()
{
	gambler->takeCards(decks);
	gambler->takeCards(decks);
}

void Game::printMenu()
{
	if (!isDouble())
	{
		std::cout << "\n1.Хватит" << std::endl << "2.Еще" << std::endl;
	} 
	else if (isDouble() && doubleNow == false)
	{
		std::cout << "\n1.Хватит" << std::endl << "2.Еще" << std::endl << "3.Удвоить\n" << std::endl;
	}
}

int Game::getChoice()
{
	int tmp;
	std::cin >> tmp;
	return tmp;
}

bool Game::replicateChoice(int choice)
{
		switch (choice)
		{
		case 1:
			dealer->getHand()->takeCard(decks);
			system("cls");
			DrawInterface();
			calculateScore();
			return false;
		case 2:
			gambler->takeCards(decks);
			return checkPerebor();
		case 3:
			if (isDouble() && doubleNow == false)
			{
				system("cls");
				cash *= 2;
				doubleNow = true;
				std::cout << "Ставка увеличена в 2 раза!! " << std::endl;
				gambler->takeCards(decks);
				DrawInterface();
			}
			break;
		default:
			break;
		}
		printMenu();
		replicateChoice(getChoice());	
}

void Game::PrintCash()
{
	std::cout << "Ваша ставка равна: " << cash << std::endl;
}


void Game::DrawInterface()
{
	PrintCash();
	printStatusDeck();
	printCardsDealer(0);
	printCardsGambler();
}

void Game::calculateScore()
{
	std::cout << std::endl;

	int countWins(0);

	int dealer_value = dealer->getHand()->calculateValue();


		int gambler_value = gambler->getHand()->calculateValue();

		if (dealer_value <= 21 && gambler_value <= 21)
		{
			if (dealer_value < gambler_value)
			{
				countWins++;
				wins++;
			}

			if (dealer_value > gambler_value)
			{
				countWins--;
			}
		}
		else
		{
			if (gambler_value < 99)
				countWins--;
			else if (dealer_value > gambler_value)
				countWins--;
			else if (gambler_value == 101)
			{
				countWins++;
				wins++;
				std::cout << "У вас два туза" << std::endl;
			}
			else if (gambler_value == 100)
			{
				countWins++;
				wins++;
				std::cout << "У вас blackJack" << std::endl;
			}
			else
			{
				countWins++;
				wins++;
			}
	}
			
		if(countWins == 0)
			std::cout << "У вас поровну. " << std::endl << "Вы остались при своих очках.";
		
		if (countWins > 0)
		{
			std::cout << "Поздравляем! Вы выиграли! Ваш выигрыш: " << cash << ".";
			gambler->setmoney(gambler->getmoney() + (cash));
		}

		if (countWins < 0)
		{
			std::cout << "Увы! Вы проиграли!";
			gambler->setmoney(gambler->getmoney() - cash);
		}
		std::cout << "\nКоличество побед: " << wins << std::endl;
			
}

void Game::dropCards()
{
	dealer->getHand()->clear();
	gambler->clear();
	doubleNow = false;
}

bool Game::checkPerebor()
{
	try
	{
		if (gambler->getHand()->calculateValue() > 21)
		{

			gambler->setmoney(gambler->getmoney() - cash);
			throw "Exception. У вас перебор!";
		}
		return true;
	}
	catch (char* str)
	{
		system("cls");
		DrawInterface();
		std::cout << "\n" << str << std::endl << "Количество побед: " << wins << std::endl;
		return false;
	}
}

bool Game::isDouble()
{
	int tmp_value;

		tmp_value = gambler->getHand()->calculateValue();
		if (tmp_value >= 9 && tmp_value <= 11)
		{
			if (cash * 2 <= gambler->getmoney())
				return true;
			else
			{
				std::cout << "Не хватает денег для удвоения" << std::endl;
				return false;
			}
		}
	return false;
}