/*Дефинирайте подходящи конструктор по подразбиране, конструктор с параметри и следните член-функции:

селектори и мутатори за член-данните;
извеждане на картата на екрана;
сравнение на две карти:
    bool isEqual (const Card& ) const.*/
#ifndef PCARD_H
#define PCARD_H
enum suits {
	Spade , Diamond, Heart, Club, endSuits
};
enum ranks {
	Two , Three, Four, Five, Six, Seven, Eight, Nine, Valet, Dame, King, Ten, Ace, endRanks
};
class PCard {
public:

	PCard();
	PCard(suits,ranks);
	void setSuit(suits);
	void setRank(ranks);
	suits getSuit()const;
	ranks getRank()const;
	bool isEqual(const PCard&)const;
	void print()const;

	PCard(const PCard&);
	PCard& operator=(const PCard&);
private:
	suits suit;
	ranks rank;
};

#endif