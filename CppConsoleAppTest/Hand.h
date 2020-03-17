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
	int getHandValue()
	{
		int total;
		for (int i = 0; i < Cards.size(); i++)
		{
			total += Cards[i].getVal();
		}
		return total;
	}

	void displayHand()
	{
		UtilSource u;
		u.print("Your Hand: ");
		for (int i = 0; i < Cards.size(); i++)
		{
			u.print(Cards[i].getFaceValue);
		}
	}

	vector<Card> Cards;

};

