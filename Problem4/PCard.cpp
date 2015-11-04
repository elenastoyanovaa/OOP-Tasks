#include "Cards.h"
#include <iostream>
using namespace std;

PCard::PCard()
{
	suit = Spade;
	rank = Two;
}
PCard::PCard(suits suit,ranks rank)
{
	this->suit = suit;
	this->rank = rank;
}
void PCard::setSuit(suits suit)
{
	this->suit = suit;
}
void PCard::setRank(ranks rank)
{
	this->rank = rank;
}
suits PCard::getSuit()const
{
	return suit;
}
ranks PCard::getRank()const
{
	return rank;
}
bool PCard::isEqual(const PCard& other)const
{
	return (rank == other.rank) ;
}
PCard::PCard(const PCard& other){
	this->rank = other.rank;
	this->suit = other.suit;
}
PCard& PCard::operator=(const PCard& other){
	if (this != &other){
		this->rank = other.rank;
		this->suit = other.suit;
	}
	return *this;
}
void PCard::print()const
{
	cout << "Card suit:" << endl;
	switch (suit)
	{
	case Spade:cout << "Spade";
		break;
	case Diamond:cout << "Diamond";
		break;
	case Heart:cout << "Heart";
		break;
	case Club:cout << "Club";
		break;
	}
	cout << endl << "Card rank:";
	switch (rank)
	{
	case Two:cout << 2;
		break;
	case Three:cout << 3;
		break;
	case Four:cout << 4;
		break;
	case Five:cout << 5;
		break;
	case Six:cout << 6;
		break;
	case Seven:cout << 7;
		break;
	case Eight:cout << 8;
		break;
	case Nine:cout << 9;
		break;
	case Valet:cout << 'J';
		break;
	case Dame:cout << 'D';
		break;
	case King:cout << 'K';
		break;
	case Ten:cout << 10;
		break;
	case Ace:cout << 'A';
		break;
	}
	cout << endl;
}