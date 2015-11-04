/*������ 2 (������� ������)
����������� ���������, ����� ������ ������� � ���������� � ��������������: ����� �� ���������� �����, ���, �������.
����������� ���������, ����� ������ ����� � ���������� � �������������� (���� �������):
����������� �����, ��������, �����, ���� � ����� ��� ��������.
��� ������� � �����, ���� �� ����������� ���������� �� ��������, �� ����� � �����.
����������� �������, �����:
�� ������� �������, ������ �������, ����� � ����;
�� �������� ��� �� �����, �� ������� ���� ��� �������� ����� �� ���;
������� ������� �� ������� ��� ������ ���������� �� ������� (��� ����� �� ������).*/
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
