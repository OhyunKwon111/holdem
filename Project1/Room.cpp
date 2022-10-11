#include "Room.h"


Room::Room(string& name, int& istep, Login *login)
{
	room_name = name;
	Plogin = login;
	Make_boot();
	cout << room_name << "�濡 ���Ű��� ȯ���մϴ�." << endl;

}

void Room::Play()
{	
	string dump;
	while (true)
	{
		switch (rstep)
		{
		case 0:
		{
			cout << "���� ���� �ο���" << player_num << "�� �Դϴ�." << endl;
			cout << "������ �����Ͻðڽ��ϱ�? ����: 1" << endl;
			cin >> dump;
			if (dump == "1")
			{
				rstep = 100;
			}
			break;
		}
		case 100:
		{
			Deal();
			Bet();
		}
		case 200:
		{
			Deal();
			Bet();
		}
		case 300:
		{
			Deal();
			Bet();
		}
		case 400:
		{
			Deal();
			Bet();
			cout << "���� ��" << endl;
			rstep =0;
		}
		default:
			break;
		}
	}
}

void Room::Make_boot()
{
	if (boot_money_list.size() != player_num)
	{
		for (int i = 0; i < boot_money_list.size(); i++)
		{	

			boot_money_list.push_back(boot_start_money);
		}
	}
}

void Room::Deal()
{
	switch (rstep)
	{
	case 100:
	{	
		for (int j = 0; j < 2; j++)
		{
			for (int i = 0; i < player_num; i++)
			{
				platers_card[i][j] = card_position;
				card_position++;
			}
		}
		break;
	}
	case 200:
	{
		for (int j = 2; j < 5; j++)
		{
			card_position++;
			for (int i = 0; i < player_num; i++)
			{
				platers_card[i][j] = card_position;
			}
		}
		break;
	}
	case 300:
	{
		for (int j = 5; j < 6; j++)
		{
			card_position++;
			for (int i = 0; i < player_num; i++)
			{
				platers_card[i][j] = card_position;
			}
		}
		break;
	}
	case 400:
	{
		for (int j = 6; j < 7; j++)
		{
			card_position++;
			for (int i = 0; i < player_num; i++)
			{
				platers_card[i][j] = card_position;
			}
		}
		break;
	}
	default:
		break;
	}
}

void Room::Bet()
{
	rstep = rstep + 100;
}