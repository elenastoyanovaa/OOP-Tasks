#include "Cards.h"
#include "Deck.h"
#include <iostream>
using namespace std;

int main()
{
	Deck p;
	p.print();
	p.mixDeck();
	cout << endl;
	p.print();
	return 0;
}