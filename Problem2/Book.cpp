#include "BooksReaders.h"
#include <iostream>
#include <assert.h>
#include <cstring>
using namespace std;

void Book::setTitle(char* title)
{
	if (this->title)
	{
		delete[]this->title;
	}
	this->title = new char[strlen(title) + 1];
	assert(this->title != NULL);
	strcpy_s(this->title, strlen(title) + 1, title);
}
void Book::setAuthor(char* author)
{
	if (this->author)
	{
		delete[]this->author;
	}
	this->author = new char[strlen(author) + 1];
	assert(this->author != NULL);
	strcpy_s(this->author, strlen(author) + 1, author);
}
void Book::isTaken()
{
	delete[]taken;
	taken = new char[4];
	strcpy(taken, "yes");
}
void Book::isntTaken()
{
	delete[]taken;
	taken = new char[3];
	strcpy(taken, "no");
}
void Book::setLibNumber(int libNumber)
{
	this->libNumber = libNumber;
}
char* Book::getTitle()const
{
	return title;
}
char* Book::getAuthor()const
{
	return author;
}
int Book::getLibNumber()const
{
	return libNumber;
}
char* Book::getTaken()const
{
	return taken;
}

void Book::print()const
{
	cout << "Title:" << title << endl
		<< "Author:" << author << endl
		<< "Library Number:" << libNumber << endl
		<< "Taken:" << taken << endl;

}

Book::Book()
{
	this->title = new char[1];
	title[0] = '\0';
	this->author = new char[1];
	author[0] = '\0';
	this->taken = new char[1];
	taken[0] = '\0';
	this->libNumber = 0;
}
Book::Book(char* title , char* author, int libNumber)
{
	this->author = new char[strlen(author) + 1];
	assert(this->author != NULL);
	strcpy(this->author, author);
	this->title = new char[strlen(title) + 1];
	assert(this->title != NULL);
	strcpy(this->title, title);
	this->taken = new char[3];
	strcpy(this->taken, "no");
	this->libNumber = libNumber;
}
bool Book::takeBook(Reader& taker)
{
	if (!strcmp(taken, "no"))
	{
		this->taker = taker;
		delete []taken;
		taken = new char[4];
		strcpy(taken, "yes");
		return true;
	}
	else
		return false;
}
Reader Book::getTaker(){
	if (taken){
		return taker;
	}
}
Book::~Book()
{
	delete[]author;
	delete[]title;
	delete[]taken;
}