/*������ 2 (������� ������)
����������� ���������, ����� ������ ������� � ���������� � ��������������: ����� �� ���������� �����, ���, �������.
����������� ���������, ����� ������ ����� � ���������� � �������������� (���� �������): 
����������� �����, ��������, �����, ���� � ����� ��� ��������. 
��� ������� � �����, ���� �� ����������� ���������� �� ��������, �� ����� � �����.
����������� �������, �����:
�� ������� �������, ������ �������, ����� � ����;
�� �������� ��� �� �����, �� ������� ���� ��� �������� ����� �� ���;
������� ������� �� ������� ��� ������ ���������� �� ������� (��� ����� �� ������).*/
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