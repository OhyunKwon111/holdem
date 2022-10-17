

#include <iostream>
#include <string>
#include "Login.h"
#include "Deck.h"
#include "Room.h"


using namespace std;


int main()
{
	Login login;
	string room_name;
	int istep = 100;
	while (true)
	{
		switch (istep)
		{
		case 100:
		{


			if (login.Confirm())
			{
				istep = 200;
				break;
			}
			else
			{
				break;
			}
		}



		case 200:
		{	

			cout << "방을 생성해주세요." << endl;
			cin >> room_name;
			if (room_name != "") {
				Room room(room_name, istep,&login);
				int play;
				cout << "게임을 시작하시겠습니까? 1: 시작 " << endl;
				cin >> play;
				if (play == 1)
				{
					room.Play();
				}
			}
			break;
		}

		case 300:
		{


			break;

		}
			








		}
	}

	return 0;
}