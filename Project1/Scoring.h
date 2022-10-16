#pragma once
#include <array>
#include <map>
#include <vector>
#include <string>
//ī�� ���� 

#define card_num_2 0x0001		// ī����� 2	0000 0000  0000 0000  0000 0000  0000 0001 
#define card_num_3 0x0002		// ī����� 3	0000 0000  0000 0000  0000 0000  0000 0010
#define card_num_4 0x0004		// ī����� 4	0000 0000  0000 0000  0000 0000  0000 0100
#define card_num_5 0x0008		// ī����� 5	0000 0000  0000 0000  0000 0000  0000 1000
#define card_num_6 0x0010		// ī����� 6	0000 0000  0000 0000  0000 0000  0001 0000
#define card_num_7 0x0020		// ī����� 7	0000 0000  0000 0000  0000 0000  0010 0000
#define card_num_8 0x0040		// ī����� 8	0000 0000  0000 0000  0000 0000  0100 0000
#define card_num_9 0x0080		// ī����� 9	0000 0000  0000 0000  0000 0000  1000 0000
#define card_num_10 0x0100		// ī����� 10	0000 0000  0000 0000  0000 0001  0000 0000
#define card_num_11 0x0200		// ī����� J	0000 0000  0000 0000  0000 0010  0000 0000
#define card_num_12 0x0400		// ī����� Q	0000 0000  0000 0000  0000 0100  0000 0000
#define card_num_13 0x0800		// ī����� K	0000 0000  0000 0000  0000 1000  0000 0000
#define card_num_14 0x1000		// ī����� A	0000 0000  0000 0000  0001 0000  0000 0000
#define card_num_sum 8191

// Ű�� �׸�

#define card_pic_spade 0x10000
#define card_pic_diamond 0x20000
#define card_pic_heart 0x40000
#define card_pic_clover 0x80000
#define card_pic_sum 983040

//���� 1048576
#define one_pair 0x100000
#define two_pair 0x200000
#define three_pair 0x400000
#define straight 0x800000
#define flush 0x1000000
#define full_house 0x2000000
#define four_pair 0x4000000
#define straight_Flush 0x8000000


using namespace std;

class Scoring
{

public:
	Scoring(array<int, 7> &hand);

public:
	void PairCheck();
	void ChangeScore(int change_score);
	int GetScore();

private:
	const static int maximum_number_of_cards = 7;
	array<int, maximum_number_of_cards >cards;
	map<int, int>num_change;
	map<int, string>pic_change;
	int score = 0;
};