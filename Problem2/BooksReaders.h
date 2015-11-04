/*«адача 2 (домашна работа)
ƒефинирайте структура, ко€то описва читател в библиотека с характеристики: номер на читателска карта, име, фамили€.
ƒефинирайте структура, ко€то описва книга в библиотека с характеристики (като минимум): 
библиотечен номер, заглавие, автор, дали е заета или свободна. 
јко книгата е заета, може да съхран€вате информаци€ за читател€, на който е заета.
ƒефинирайте функци€, ко€то:
по подаден читател, намира книгата, ко€то е заел;
по подадено име на книга, да провери дали има свободно копие от не€;
сортира книгите по азбучен ред според заглавието на книгита (или името на автора).*/
#ifndef BANDR_H
#define BANDR_H
struct Reader {
public:
	void setFirstName(char*);
	void setNumber(int);
	void setLastName(char*);
	char* getFirstName()const;
	int getNumber()const;
	char* getLastName()const;

	void print()const;

	Reader();
	Reader(char*, char*, int);
	~Reader();
private:
	int number;
	char*firstName;
	char*lastName;
};
struct Book {
	void setTitle(char*);
	void setLibNumber(int);
	void setAuthor(char*);
	char* getTaken()const;
	char* getTitle()const;
	int getLibNumber()const;
	char* getAuthor()const;
	Reader getTaker();
	void print()const;
	bool takeBook(Reader&);
	void isTaken();
	void isntTaken();

	Book();
	Book(char*, char*, int);
	~Book();
private:
	int libNumber;
	char* title;
	char* author;
	char* taken;
	Reader taker;
};
#endif