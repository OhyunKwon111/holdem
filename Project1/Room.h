#pragma once
#include <string>
#include "Deck.h"
#include "Login.h"
#include <iostream>
#include <vector>
#include <array>
using namespace std;

class Room
{
public:
	Room(string& name,int& istep, Login *login);
	~Room() {};
	void Play();
	void Make_boot();
	void Deal();
	void Bet();

private:
	int shuffle_num = 1000;
	int player_num = 3;
	int boot_start_money = 100000;
	int rstep = 0;
	int card_position = 0;
	string room_name;
	Login *Plogin;
	vector<int>boot_money_list;
	array<array<int, 7>, 9>platers_card;
	vector<string>boot_name_list;
};

