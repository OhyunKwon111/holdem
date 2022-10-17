#include "Login.h"




Login::Login()
{
	string num;
	string filePath = "player.csv";
	ifstream file(filePath.data());

	if (file.is_open())
	{
		while (getline(file, num, '\n'))
		{
			player_list.push_back(num);
		}

		file.close();
	}
}

Login::~Login()
{

}

string Login::GetPlayerList(int num)
{
	return player_list[num];
}

bool Login::Confirm()
{
	string id;
	string password;
	cout << "아이디를 입력해 주세요." << endl;
	cin >> id;
	cout << "비밀번호를 입력해 주세요." << endl;
	cin >> password;

	for (int i = 0; i < player_list.size(); i++)
	{

		string dump = player_list[i];
		stringstream stream(dump);
		getline(stream, dump, ',');

		if (id.compare(dump) == 0)
		{
			player_id = dump;
			getline(stream, dump, ',');
			if (password.compare(dump) == 0)
			{	
				getline(stream, dump, ',');
				player_money = stoi(dump);
				cout << player_id << "님 환영합니다" << endl;
				join = true;
				return true;
			}
		}
	}
	player_id = "0";
	cout << "등록된 id가 없거나 password 가 잘못되었습니다. " << endl;
	return false;
}


string Login::GetId()
{
	return player_id;
}

int Login::GetMoney()
{
	return player_money;
}