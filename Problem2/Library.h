/*������ 2 (������� ������)
������������ � ��������� �� ����� � ��������� �� ��������.����������� �������� ��������������� :
�������� �� ��� �������(��� � ��������);
�������� �� ���� �����(��� � ��������);
��������� �� �����(�� ����������� �����);
������� � ������� �� �����.
����������� �������, �����:
�� ������� �������, ������ �������, ����� � ����;
�� �������� ��� �� �����, �� ������� ���� ��� �������� ����� �� ���;
������� ������� �� ������� ��� ������ ���������� �� �������(��� ����� �� ������).*/
#ifndef LIB_H
#define LIB_H
#include "BooksReaders.h"

class Library
{
public:
	void print()const;

	void addReader(const Reader&);
	void addBook(const Book&);
	void returnBook( Book&);
	bool removeBook(const Book&);

	Book& findTaken(const Reader&);
	bool hasCopy(char*);
	void sortBooks();

	Library();
	~Library();
	Library& operator=(const Library&);
	Library(const Library&);
private:
	Book* books;
	Reader* readers;
	int maxBooks;
	int numberOfBooks;
	int maxReaders;
	int numberOfReaders;
};
#endif