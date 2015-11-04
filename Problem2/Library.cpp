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
#include "BooksReaders.h"
#include "Library.h"
#include <iostream>
#include <assert.h>
#include <cstring>
using namespace std;

void Library::print()const
{
	cout << "Books:" << endl;
	for (int i = 0; i < numberOfBooks; i++)
	{
		books[i].print();
		cout << endl;
	}
	cout << "Readers:" << endl;
	for (int i = 0; i < numberOfReaders; i++)
	{
		readers[i].print();
		cout << endl;
	}
}

void Library::addReader(const Reader& newOne)
{
		if (numberOfReaders == maxReaders)
		{
			maxReaders *= 2;
			Reader* old = readers;
			readers = new Reader[maxReaders];

			for (int i = 0; i < numberOfReaders; ++i)
			{
				readers[i] = old[i];
			}
			delete[] old;
		}
		readers[numberOfReaders++] = newOne;
}
void Library::addBook(const Book& newOne)
{
	if (numberOfBooks == maxBooks)
	{
		maxBooks *= 2;
		Book* old = books;
		books = new Book[maxBooks];

		for (int i = 0; i < numberOfBooks; ++i)
		{
			books[i] = old[i];
		}
		delete[] old;
	}
	books[numberOfBooks++] = newOne;
}
void Library::returnBook(Book& book)
{
	delete[]book.getTaken();
	book.isntTaken();

}
bool Library::removeBook(const Book& book)
{
	bool isFound = false;
	for (int i = 0; i < numberOfBooks - 1; i++)
	{
		if (!strcmp(books[i].getTitle(), book.getTitle()))
		{
			isFound = true;
			for (int j = i + 1; j < numberOfBooks; j++)
			{
				books[j - 1] = books[j];
			}
		}
	}
	if (!isFound)
	{
		if (!strcmp(books[numberOfBooks - 1].getTitle(),book.getTitle()))
		{
			--numberOfBooks;
			isFound = true;
		}
	}
	else


	{
		numberOfBooks--;
	}
	return isFound;

}

Book& Library::findTaken(const Reader& taker)
{
	for (int i = 0; i < numberOfBooks; i++)
	{
		if (taker.getNumber() == books[i].getTaker().getNumber())
		{
			return books[i];
		}
	}
}
bool Library::hasCopy(char* title)
{
	for (int i = 0; i < numberOfBooks; i++)
	{
		if (!strcmp(title, books[i].getTitle()))
		{
			if (!strcmp(books[i].getTaken(), "no"))
			{
				return true;
				break;
			}

			else
				return false;
		}
		else
			return false;
	}
}
void Library::sortBooks()
{
		int i, j, min;
		Book temp;

		for (i = 0; i < numberOfBooks; i++) {
			min = i;
			for (j = i + 1; j < numberOfBooks; j++) {
				if (strcmp(books[j].getTitle(), books[min].getTitle()) < 0) {
					min = j;
				}
			}
			temp = books[min];
			books[min] = books[i];
			books[i] = temp;
		}
	
}

Library::Library()
{
	books = new Book[1];
	readers = new Reader[1];
	numberOfBooks = 0;
	maxBooks = 1;
	numberOfReaders = 0;
	maxReaders = 1;
}
Library::~Library()
{
	delete[]books;
	delete[]readers;
}
Library& Library::operator=(const Library& other)
{
	if (this != &other)
	{
		delete[]books;
		delete[]readers;
		this->readers = new Reader[other.maxReaders];
		assert(this->readers != NULL);
		for (int i = 0; i < other.numberOfReaders; i++)
		{
			readers[i] = other.readers[i];
		}
		this->numberOfReaders = other.numberOfReaders;
		this->maxReaders = other.maxReaders;
		this->books = new Book[other.maxBooks];
		assert(this->books != NULL);
		for (int i = 0; i < other.numberOfBooks; i++)
		{
			books[i] = other.books[i];
		}
		this->numberOfBooks = other.numberOfBooks;
		this->maxBooks = other.maxBooks;
	}
	return *this;
}
Library::Library(const Library& other) :books(NULL), readers(NULL)
{
	this->readers = new Reader[other.maxReaders];
	assert(this->readers != NULL);
	for (int i = 0; i < other.numberOfReaders; i++)
	{
		readers[i] = other.readers[i];
	}
	this->numberOfReaders = other.numberOfReaders;
	this->maxReaders = other.maxReaders;
	this->books = new Book[other.maxBooks];
	assert(this->books != NULL);
	for (int i = 0; i < other.numberOfBooks; i++)
	{
		books[i] = other.books[i];
	}
	this->numberOfBooks = other.numberOfBooks;
	this->maxBooks = other.maxBooks;
}

int main()
{
	Book a("Apple", "John", 1);
	a.print();

	return 0;
}