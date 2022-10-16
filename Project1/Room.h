#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <array>
#include "Deck.h"
#include "Login.h"
#include "Player.h"


using namespace std;

class Room
{
public:
	Room(string& name,int& istep, Login *login);
	~Room() {};
	void Play();
	void Deal();
	void Bet();

private:
	int shuffle_num = 1000;
	int player_num = 3;
	int boot_start_money = 100000;
	int rstep = 0;
	int card_order = 0;
	string room_name;
	string mode;
	int bot_money = 500000;
	Login* plogin;
	Deck* deck;
	vector<Player>player_list;
};

