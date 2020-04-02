// CppConsoleAppTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <istream>
#include "UtilSource.h"
#include "Deck.h"
#include "Card.h"
#include "Hand.h"
#include <cstdlib>
#include "GameUtil.h"
#include "Player.h"
using std::string;
using std::vector;

int main() {
	UtilSource _u;
	GameUtil _gu;
	string input;
	Deck theDeck;
	Player playerOne;
	Player dealer;
	Hand playerHand;
	Hand dealersHand;
	vector<Card> dealersCards;
	vector<Card> playerCards;
	playerHand.Cards = playerCards;
	dealersHand.Cards = dealersCards;
	playerOne.Hand = playerHand;
	dealer.Hand = dealersHand;
	dealer.Name = "Dealer";
	bool correctInput = false;
	bool gameOver = false;
	//prompt user
	_u.print("Ready to play Black Jack?");
	_u.print("Enter (y) to play or (n) to exit.");
	
	while (!correctInput) {
		//get input
		std::cin >> input;
		if (input == "y")
		{
			_u.print("Lets Begin!");
			_u.print("Enter your Name");
			playerOne.Name = _u.getInput();
			correctInput = true;
		}
		else if (input == "n") {
			_u.print("Exiting Game...");
			correctInput = true;
			exit(0);
		}
		else {
			_u.print("Enter (y) to play or (n) to exit.");
		}
	}
	
	//build 1 deck
	theDeck.BuildDeck();
	//draw 2 cards into player hand
	_u.print("Drawing your cards...");
	//card1
	_gu.Draw(playerOne.Hand, theDeck);
	//card 2
	_gu.Draw(playerOne.Hand, theDeck);
	//show player hand
	playerOne.Hand.displayHand();
	_u.print(_u.toStr(playerOne.Hand.getHandValue()));
	//Prompt the dealers hand is being drawn
	_u.print("Drawing the Dealer's hand...");
	//draw dealers hand
	_gu.Draw(dealer.Hand, theDeck);
	_gu.Draw(dealer.Hand, theDeck);

	if (_gu.bjack(playerOne.Hand)) {
		_u.print("Black Jack! You WIN!");
		gameOver = true;
		return 0;
	}
	else if (_gu.bjack(dealer.Hand)) {
		_u.print("Black Jack! Dealer WINs...");
		_u.print("Dealers hand..");
		dealer.Hand.displayHand();
		_u.print("Dealer total:");
		_u.print(_u.toStr(dealer.Hand.getHandValue()));
		gameOver = true;
		return 0;
	}
	//game loop
	while (!gameOver) {
		_u.print("Hit or Stay? Enter: (h) or (s)");
		std::cin >> input;

		while(input == "h" && !gameOver) {
			_gu.Draw(playerOne.Hand, theDeck);
			gameOver = _gu.playerTurn(playerOne);
			if (!gameOver) 
			{
				_gu.showStats(playerOne);
			}
			_gu.clearInput(input);
		}
		/*if(input == "s") {
			_u.print("You stayed your hand at :" + _u.toStr(playerHand.getHandValue()));
		}
		if (dealersHand.getHandValue() <= 16) {
			_u.print("Dealers draw..");
			_gu.Draw(dealersHand, theDeck);

		}*/
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
