#include "Room.h"


Room::Room(string& name, int& istep, Login *login)
{
	room_name = name;
	plogin = login;
	deck = new Deck();

	Player* user = new User(login->GetMoney(),login->GetId());
	player_list.push_back(user);
	cout << room_name << "방에 오신것을 환영합니다." << endl;
	

	for (int i = 1; i <=player_num; ++i)
	{
		Player* bot = new Bot(bot_money);
		player_list.push_back(bot);
	}
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
			cout << "현재 방의 인원은" << player_num << "명 입니다." << endl;
			cout << "게임을 시작하시겠습니까? 시작: 1" << endl;
			cin >> dump;
			if (dump == "1")
			{
				deck->DeckShuffle(shuffle_num);
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
			ScoreComparison();
			cout << "게임 끝" << endl;
			rstep =0;
		}
		default:
			break;
		}
	}
}



void Room::Deal()
{
	switch (rstep)
	{
	case 100:
	{	
		for (int order = 0; order < 2; order++)
		{
			for (int i = 0; i < player_num; i++)
			{
				card_order++;
				player_list[i]->SetHand(deck->GetCard(card_order));
			}
		}
		break;
	}
	case 200:
	{
		for (int order = 2; order < 5; order++)
		{
			card_order++;
			for (int i = 0; i < player_num; i++)
			{
				player_list[i]->SetHand(deck->GetCard(card_order));
			}
		}
		break;
	}
	case 300:
	{			
		card_order++;
		for (int order = 5; order < 6; order++)
		{
			for (int i = 0; i < player_num; i++)
			{
				player_list[i]->SetHand(deck->GetCard(card_order));
			}
		}
		break;
	}
	case 400:
	{
		for (int order = 6; order < 7; order++)
		{
			card_order++;
			for (int i = 0; i < player_num; i++)
			{
				player_list[i]->SetHand(deck->GetCard(card_order));
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

void Room::ScoreComparison()
{
	
	for (int i = 0; i < player_num; i++)
	{
		score_list.push_back(player_list[i]->GetScore());
		cout << player_list[i]->GetScore() << endl;
	}




}