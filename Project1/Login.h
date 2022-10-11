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

	string Get_player_list(int num);
	bool Confirm();
	bool Get_id(string& id);
	bool Get_money(int& money);
	

private:
	string player_id;
	int player_money;
	vector<string> player_list;
	bool join = false;
};

