/*����������� ����, ����� ������ ������ �� ����� ��� �������� ��������������:

����� �� ����� (������ �� �����, ��������� � ����������� ������);
������ top, ����� ������� ��� � ������� �� ����� �� ��������.
����������� ����������� �� �����������, ����� ������������ �������� �� 52 �����. ����������� ����-������� ��:

��������� �� �������� �� ����������� �����;
�������� ���� �������� � ������
    // ���� �� ��������� ������ �����
    bool isEmpty() const;
��������� �� �����: ����� �� �������, ����� � ���-������ �� ��������;
����������� �� ������� � ��������. ������ �� ���������� ���������� �� Fisher - Yates.*/
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