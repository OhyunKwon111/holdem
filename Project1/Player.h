#pragma once
#include <string>
#include <array>
#include "Scoring.h"

using namespace std;

class Player
{
public:
	virtual void SetHand(int card) = 0;
	virtual int GetScore() = 0;
};




class Bot :public Player
{	

public:
	Bot(int money);

public:

	void SetHand(int card);
	int GetScore();

private:
	int player_money;
	int score = 0;
	int number_of_cards = 0;
	const static int maximum_number_of_cards = 7;
	array<int, maximum_number_of_cards >hand;
	
};



class User :public Player
{

public:
	User(int money, string id);

public:

	void SetHand(int card);
	int GetScore();

private:

	string UserId;
	int player_money;
	int score = 0;
	int number_of_cards = 0;
	const static int maximum_number_of_cards = 7;
	array<int, maximum_number_of_cards >hand;
};