#pragma once
#include "Card.h"
#include <iostream> 
#include <vector> 
#include "UtilSource.h"
using std::vector;
using std::string;

class Deck
{
public:
	Deck();
	~Deck();
	vector<std::string> Suits = {"Hearts","Spades","Clubs","Diamonds"};
	vector<Card> Cards;
	UtilSource _u;
	void BuildDeck()
	{
		int length = Suits.size() - 1;
		for (int k = 0; k <= length; k++)
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

	Card getRandomCard() 
	{
		srand(time(NULL));
		int index = rand() % (Cards.size() - 1) + 1;
		return Cards[index];
	};

	void removeCard(Card card)
	{
		vector<Card> newCards;
		for (int i = 0; i < Cards.size(); i++)
		{
			bool match = Cards[i].getVal() == card.getVal() && Cards[i].getSuit() == card.getSuit();
			if (!match)
			{
				newCards.push_back(Cards[i]);
			}
		}
		Cards.clear(); 
		Cards = newCards;
	};

	void displayDeck()
	{
		for (int i = 0; i < Cards.size(); i++)
		{
			 _u.print(Cards[i].getFaceValue() + " Of " + Cards[i].getSuit());
		}
	}
};

