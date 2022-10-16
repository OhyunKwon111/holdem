#include <string>
#include <array>


using namespace std;

class Player
{
public:
	virtual void SetHand(int card) = 0;
};




class Bot :public Player
{	

//public:
//	Bot(int money);

public:

	void SetHand(int card);


private:
	int PlayerMoney;
	int Score = 0;
	int NumberOfCards = 0;
	const static int MaximumNumberOdCards = 7;
	array<int, MaximumNumberOdCards >Hand;
	
};



class User :public Player
{

//public:
//	User(int money, string id);
//
public:

	void SetHand(int card);


private:
	int PlayerMoney;
	int Score = 0;
	string UserId;
	int NumberOfCards = 0;
	const static int MaximumNumberOdCards = 7;
	array<int, MaximumNumberOdCards >Hand;
};