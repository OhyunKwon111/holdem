#include "Player.h"

Bot::Bot(int money)
{
	player_money = money;
	hand = { 0,0,0,0,0,0,0 };
}


void Bot::SetHand(int card)
{
	if (number_of_cards < maximum_number_of_cards)
	{
		hand[number_of_cards] = card;
		number_of_cards++;
	}
}

int Bot::GetScore()
{
	Scoring scoring(hand);
	score = scoring.GetScore();
	number_of_cards = 0;
	return score;
}



User::User(int money,string id)
{
	player_money = money;
	UserId = id;
	hand = { 0,0,0,0,0,0,0 };
}

void User::SetHand(int card)
{
	if (number_of_cards < maximum_number_of_cards)
	{
		hand[number_of_cards] = card;
		number_of_cards++;
	}
}

int User::GetScore()
{
	Scoring scoring(hand);
	score = scoring.GetScore();
	number_of_cards = 0;
	return score;
}