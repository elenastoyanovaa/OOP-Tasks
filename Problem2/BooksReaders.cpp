/*«адача 2 (домашна работа)
ƒефинирайте структура, ко€то описва читател в библиотека с характеристики: номер на читателска карта, име, фамили€.
ƒефинирайте структура, ко€то описва книга в библиотека с характеристики (като минимум):
библиотечен номер, заглавие, автор, дали е заета или свободна.
јко книгата е заета, може да съхран€вате информаци€ за читател€, на който е заета.
ƒефинирайте функци€, ко€то:
по подаден читател, намира книгата, ко€то е заел;
по подадено име на книга, да провери дали има свободно копие от не€;
сортира книгите по азбучен ред според заглавието на книгита (или името на автора).*/
#include "BooksReaders.h"
#include <iostream>
#include <assert.h>
#include <cstring>
using namespace std;

void Reader::setFirstName(char* firstName)
{
	if (this->firstName)
	{
		delete[]this->firstName;
	}
	this->firstName = new char[strlen(firstName) + 1];
	assert(this->firstName != NULL);
	strcpy_s(this->firstName, strlen(firstName) + 1, firstName);
}
void Reader::setLastName(char* lastName)
{
	if (this->lastName)
	{
		delete[]this->lastName;
	}
	this->lastName = new char[strlen(lastName) + 1];
	assert(this->lastName != NULL);
	strcpy_s(this->lastName, strlen(lastName) + 1, lastName);
}
void Reader::setNumber(int number)
{
	this->number = number;
}
char* Reader::getFirstName()const
{
	return firstName;
}
char* Reader::getLastName()const
{
	return lastName;
}
int Reader::getNumber()const
{
	return number;
}

void Reader::print()const
{
	cout << "Name:" << firstName << " " << lastName << endl
		<< "number:" << number << endl;
}

Reader::Reader()
{
	this->firstName = new char[1];
	firstName[0] = '\0';
	this->lastName = new char[1];
	lastName[0] = '\0';
	this->number = 0;
}
Reader::Reader(char* firstName , char* lastName , int number )
{
	this->lastName = new char[strlen(lastName) + 1];
	assert(this->lastName != NULL);
	strcpy(this->lastName, lastName);
	this->firstName = new char[strlen(firstName) + 1];
	assert(this->firstName != NULL);
	strcpy(this->firstName, firstName);
	this->number = number;
}
Reader::~Reader()
{
	delete[]lastName;
	delete[]firstName;
}
