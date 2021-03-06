#include "SimpleGame.h"


SimpleGame::SimpleGame()
{
}


SimpleGame::~SimpleGame()
{
}

int SimpleGame::getCardValue(Card card)
{
	if (card.isNumber) 
	{
		return stoi(card.symbol);
	}
	else if (card.symbol == "J") 
	{
		return 11;
	}
	else if (card.symbol == "Q")
	{
		return 12;
	}
	else if (card.symbol == "K")
	{
		return 13;
	}
	else if (card.symbol == "A")
	{
		return 14;
	}
	
	return 0;
}

vector<int> SimpleGame::evaluateGame(vector<Card> move)
{
	vector<int> winners;
	int bestVal = 0;
	int bestCard = 0;

	// Get winning card
	for (size_t i = 0; i < move.size(); i++)
	{
		int cardVal = getCardValue(move[i]);

		if (cardVal > bestVal)
		{
			bestVal = cardVal;
			bestCard = i;
		}
	}

	// Check for ties
	for (size_t i = 0; i < move.size(); i++)
	{
		int cardVal = getCardValue(move[i]);

		if (cardVal == bestVal)
		{
			winners.push_back(i);
		}
	}

	return winners;
}
