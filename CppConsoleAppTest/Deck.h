#pragma once
#include "Card.h"
#include <iostream> 
#include <vector> 
using std::vector;
using std::string;

class Deck
{
public:
	Deck();
	~Deck();
	vector<std::string> Suits = {"Hearts","Spades","Clubs","Diamonds"};
	vector<Card> Cards;

	void BuildDeck()
	{
		int length = Suits.size() - 1;
		for (int k = 0; k < length; k++)
		{
			string suit = Suits[k];
			for (int i = 1; i < 14; ++i) {
				Card cardToAdd;
				cardToAdd.setSuit(suit);
				cardToAdd.setValue(i);
				Cards.push_back(cardToAdd);
			}
		}
		
	};
};

