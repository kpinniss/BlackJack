#pragma once

#include <iostream>
#include <string>
#include <istream>
#include "UtilSource.h"
#include "Deck.h"
#include "Card.h"
#include "Hand.h"
#include <cstdlib>

class Player
{
public:
	Player();
	~Player();

	string Name;

	Hand Hand;

};

