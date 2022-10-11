#pragma once
#include <array>
#include <iostream>
#include <random>

using namespace std;

//카드 숫자 

#define card_num_2 0x0001		// 카드숫자 2	0000 0000  0000 0000  0000 0000  0000 0001 
#define card_num_3 0x0002		// 카드숫자 3	0000 0000  0000 0000  0000 0000  0000 0010
#define card_num_4 0x0004		// 카드숫자 4	0000 0000  0000 0000  0000 0000  0000 0100
#define card_num_5 0x0008		// 카드숫자 5	0000 0000  0000 0000  0000 0000  0000 1000
#define card_num_6 0x0010		// 카드숫자 6	0000 0000  0000 0000  0000 0000  0001 0000
#define card_num_7 0x0020		// 카드숫자 7	0000 0000  0000 0000  0000 0000  0010 0000
#define card_num_8 0x0040		// 카드숫자 8	0000 0000  0000 0000  0000 0000  0100 0000
#define card_num_9 0x0080		// 카드숫자 9	0000 0000  0000 0000  0000 0000  1000 0000
#define card_num_10 0x0100		// 카드숫자 10	0000 0000  0000 0000  0000 0001  0000 0000
#define card_num_11 0x0200		// 카드숫자 J	0000 0000  0000 0000  0000 0010  0000 0000
#define card_num_12 0x0400		// 카드숫자 Q	0000 0000  0000 0000  0000 0100  0000 0000
#define card_num_13 0x0800		// 카드숫자 K	0000 0000  0000 0000  0000 1000  0000 0000
#define card_num_14 0x1000		// 카드숫자 A	0000 0000  0000 0000  0001 0000  0000 0000

// 키드 그림

#define card_pic_spade 0x10000
#define card_pic_diamond 0x20000
#define card_pic_heart 0x40000
#define card_pic_clover 0x80000


//족보
#define One_pair 0x100000
#define Two_pair 0x200000
#define Three_pair 0x400000
#define Straight 0x800000
#define Flush 0x1000000
#define Full_house 0x2000000
#define Four_pair 0x4000000
#define Straight_Flush 0x8000000

class Deck
{

public:
	Deck();
	~Deck() {};
	void Get_deck();
	void Deck_shuffle(int num);

private:
	array<int, 13> card_num;
	array<int, 4> card_pic;
	array<int, 52> deck;
};

