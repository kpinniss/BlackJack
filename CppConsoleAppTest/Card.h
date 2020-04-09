#pragma once
#include <string>
#include "UtilSource.h"
#include <cstdlib>
#include <string>

class Card
{
private :
	int Value;
	std::string Suit;
public:
	Card();
	~Card();
	UtilSource _u;

	void setSuit(std::string val)
	{
		Suit = val;
	}

	void setValue(int val)
	{
		Value = val;
	};

	std::string getSuit()
	{
		return Suit;
	}


	int getVal() 
	{
		return Value;
		
	}

	std::string getFaceValue() 
	{
		if (Value == 1) {
			return "ace";
		}
		if (Value == 13) {
			return "king";
		}
		if (Value == 12) {
			return "queen";
		}
		if (Value == 11) {
			return "jack";
		}
		else{
			return _u.toStr(Value);
		}
	}

	void displayCard() 
	{
		_u.print(getFaceValue() + " Of " + getSuit());
	}

};

