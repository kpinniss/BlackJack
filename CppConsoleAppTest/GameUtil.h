#pragma once
#include <iostream>
#include <string>
#include <istream>
#include "UtilSource.h"
#include "Deck.h"
#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include <cstdlib>

class GameUtil
{
public:
	GameUtil();
	~GameUtil();
	UtilSource _u;
	void Draw(Hand &hand, Deck &deck)
	{
		Card card = deck.getRandomCard();
		hand.addCard(card);
		deck.removeCard(card);
	}

	bool Bust(Hand hand)
	{
		return hand.getHandValue() > 21;
	}

	bool bjack(Hand hand)
	{
		return hand.getHandValue() == 21;
	}

	void Win(Player player)
	{
		_u.print("Black Jack " + player.Name + " Wins!");
	}

	void Lose(Player player)
	{
		_u.print("Bust! " + player.Name + " Loses");
		player.Hand.displayHand();
	}

	void showStats(Player player)
	{
		player.Hand.displayHand();
		_u.print(_u.toStr(player.Hand.getHandValue()));
	}

	bool playerTurn(Player player)
	{
		bool gameOver = false;
		if (Bust(player.Hand))
		{
			Lose(player);
			gameOver = true;
		}
		else if (bjack(player.Hand))
		{
			Win(player);
			gameOver = true;
		}
		return gameOver;
	}

	void clearInput(string &input)
	{
		input = "";
	}
};