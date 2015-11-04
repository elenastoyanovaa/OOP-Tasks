/*Задача 2 (домашна работа)
Библиотеката е множество от книги и множество от читатели.Дефинирайте следните функционалности :
добавяне на нов читател(ако е възможно);
добавяне на нова книга(ако е възможно);
бракуване на книга(по библиотечен номер);
заемане и връщане на книга.
Дефинирайте функция, която:
по подаден читател, намира книгата, която е заел;
по подадено име на книга, да провери дали има свободно копие от нея;
сортира книгите по азбучен ред според заглавието на книгита(или името на автора).*/
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