#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <vector>
#include <sstream>

using namespace std;

class Login
{
public:

	Login();
	~Login();

	string GetPlayerList(int num);
	bool Confirm();
	string GetId();
	int GetMoney();
	

private:
	string player_id;
	int player_money;
	vector<string> player_list;
	bool join = false;
};

