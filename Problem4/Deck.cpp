#include <iostream>
#include <assert.h>
#include "Cards.h"
#include "Deck.h"
using namespace std;

Deck::Deck()
{

	top = maxCapacity;
	int p = 0;
	this->cards = new PCard[maxCapacity];
	for (suits i = Spade; i <endSuits; i = suits(i + 1))
	{
		for (ranks j = Two; j < endRanks; j = ranks(j + 1))
		{
			cards[p] = PCard(i,j);
			p++;
		}
	}
}
Deck::Deck(const Deck& other){
	top = other.top;
	this->cards = new PCard[maxCapacity];
	for (int i = 0; i < top; i++){
		this->cards[i] = other.cards[i];
	}
}
Deck& Deck::operator=(const Deck& other){
	if (this != &other){
		delete[]this->cards;
		top = other.top;
		this->cards = new PCard[maxCapacity];
		for (int i = 0; i < top; i++){
			this->cards[i] = other.cards[i];
		}
	}
	return *this;
}
Deck::~Deck(){
	delete[]cards;
}

void Deck::print()const
{
	for (int i = 0; i < top; i++)
	{
		cards[i].print();
	}
}
bool Deck::isEmpty()const
{
	return (top == 0);
}
PCard& Deck::giveCard()
{
	if (!isEmpty())
	{	
		return cards[top--];
	}
}