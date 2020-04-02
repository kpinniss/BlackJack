#pragma once
#include "Card.h"
#include <iostream> 
#include <vector> 
using std::vector;
using std::string;

class Hand
{
public:
	Hand();
	~Hand();

	vector<Card> Cards;

	int getHandValue()
	{
		int total = 0;
		for (int i = 0; i < Cards.size(); i++)
		{
			total += Cards[i].getVal();
		}
		return total;
	}

	void displayHand()
	{
		UtilSource u;
		u.print("Hand: ");
		for (int i = 0; i < Cards.size(); i++)
		{
			Cards[i].displayCard();
		}
	}

	void addCard(Card card)
	{
		Cards.push_back(card);
	}

};

