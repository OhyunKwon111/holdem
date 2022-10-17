#include "Scoring.h"

Scoring::Scoring(array<int, 7> &hand)
{
	cards = hand;
	num_change.insert({ card_num_2,2 }), num_change.insert({ card_num_3,3 }), num_change.insert({ card_num_4,4 }), num_change.insert({ card_num_5,5 });
	num_change.insert({ card_num_6,6 }), num_change.insert({ card_num_7,7 }), num_change.insert({ card_num_8,8 }), num_change.insert({ card_num_9,9 });
	num_change.insert({ card_num_10,10 }), num_change.insert({ card_num_11,11 }), num_change.insert({ card_num_12,12 }), num_change.insert({ card_num_13,13 });
	num_change.insert({ card_num_14,14 });

}

void Scoring::ChangeScore(int change_score)
{
	if (score < change_score)
	{
		score = change_score;
	}
}

int Scoring::GetScore()
{
	PairCheck();
	StraightCheck();
	return score;
}

void Scoring::PairCheck()
{	
	int dump;
	int card_sum = 0;
	map<int, int, greater<int>>m_dump;
	for (int i = 0; i < maximum_number_of_cards; ++i)
	{
		dump = cards[i] & card_num_sum;
		card_sum = dump + card_sum;
		if (m_dump.find(dump) == m_dump.end()) {
			m_dump.insert({ dump ,1 });
		}
		else {
			m_dump[dump] = m_dump[dump] + 1;
		}
	}

	std::vector<int> four;
	std::vector<int> three;
	std::vector<int> two;
	std::vector<int> one;
	for (auto it = m_dump.begin(); it != m_dump.end(); it++) {
		if (it->second == 4) {
			four.push_back(it->first);
		}
		else if (it->second == 3) {
			three.push_back(it->first);
		}
		else if (it->second == 2) {
			two.push_back(it->first);
		}
	}
	int change_score;
	if (four.size() != 0)
	{

		if (m_dump.begin()->first == four[0]) {
			change_score = four_pair + (num_change[(four[0])] * 100) + num_change[(m_dump.begin()++->first)];
		}
		else
		{
			change_score = four_pair + (num_change[(four[0])]*100) + num_change[(m_dump.begin()->first)];
		}
		ChangeScore(change_score);
	}
	else if (three.size() != 0)
	{
	
		if (three.size() == 2 )
		{
			change_score = full_house + (num_change[(three[0])] * 100) + num_change[(three[1])];
		}
		else if(two.size() != 0)
		{
			change_score = full_house + (num_change[(three[0])] * 100) + num_change[(two[0])];
		}
		else
		{
			change_score = three_pair + (num_change[(three[0])] * 100);
		}
		ChangeScore(change_score);
	}
	else if (two.size() != 0)
	{
		if (two.size() >= 2)
		{
			change_score = two_pair + (num_change[(two[0])] * 100) + (num_change[(two[1])] * 100);
		}
		else
		{
			change_score = one_pair + (num_change[(two[0])] * 100);
		}
		ChangeScore(change_score);
	}
	else
	{
		ChangeScore(card_sum);
	}
}

void Scoring::StraightCheck()
{
	int straight_5 = 4111;
	int straight_14 = 7936;
	int card_sum = 0;
	int change_score = 0;
	for (int i = 0; i < maximum_number_of_cards; ++i)
	{
		card_sum = cards[i] + card_sum;
	}

	
	for (int i = 0,j = 1; i < 9; i++)
	{
		if ((card_sum & straight_14 / j) == straight_14)
		{
			int change_score = straight + 14 -i;
		}
		j = j * 2;
	}
	if ((card_sum & straight_5) == straight_5)
	{
		int change_score = straight + 5;
	}
}

void Scoring::FlushCheck()
{

}