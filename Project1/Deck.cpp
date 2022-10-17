#include "Deck.h"



Deck::Deck()
{

	card_num = { card_num_2 ,card_num_3 ,card_num_4 ,card_num_5 ,card_num_6 ,card_num_7 ,card_num_8 ,card_num_9 ,card_num_10 ,card_num_11 ,card_num_12 ,card_num_13 ,card_num_14 };
	card_pic = { card_pic_spade ,card_pic_diamond ,card_pic_heart ,card_pic_clover };
	
	for (int i = 0; i < card_pic.size(); i++)
	{
		for (int j = 0; j < card_num.size(); j++)
		{
			deck[(i*13)+j] = card_pic[i] + card_num[j];
		}
	}

}


void Deck::GetDeck()
{
	for (int i = 0; i < deck.size(); i++) {
		cout << deck[i] << endl;
	}
}

int Deck::GetCard(int card_order)
{
	return deck[card_order];
}


void Deck::DeckShuffle(int shuffle_num)
{	
	int dump;
	int dump_1;
	int dump_2;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 51);
	dump_1 = dis(gen);
	dump = deck[dump_1];
	for (int i = 0; i < shuffle_num; i++)
	{
		dump_2 = dis(gen);
		deck[dump_1] = deck[dump_2];
		dump_1 = dump_2;
	}
	deck[dump_1] = dump;
}