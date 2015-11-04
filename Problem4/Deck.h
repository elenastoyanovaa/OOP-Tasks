/*Дефинирайте клас, който описва колода от карти със следните характеристики:

масив от карти (обекти от класа, дефиниран в предходната задача);
индекс top, който посочва коя е картата на върха на колодата.
Дефинирайте конструктор по поразбиране, който инициализира колодата от 52 карти. Дефинирайте член-функции за:

извеждане на колодата на стандартния изход;
проверка дали колодата е празна
    // дали са раздадени всички карти
    bool isEmpty() const;
раздаване на карта: връща се картата, която е най-отгоре на колодата;
разбъркване на картите в колодата. Можете да използвате алгоритъма на Fisher - Yates.*/
#ifndef DECK_H
#define DECK_H

#include "Cards.h"
#include <iostream>
using namespace std;

class Deck {
public:
	Deck();
	Deck(const Deck& );
	Deck& operator=(const Deck& );
	~Deck();
	void print()const;
	bool isEmpty()const;
	PCard& giveCard();
	void mixDeck()
	{
		for (int i = top - 1; i > 0; --i)
		{
			swap(cards[i], cards[rand() % (i + 1)]);
		}
	}
	void removeCard(PCard&);
private:
	PCard* cards;
	int top;
	int maxCapacity=52;
};
#endif