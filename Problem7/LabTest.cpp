#include "Test.h"
#include "Pack.h"
#include "LabTest.h"
#include <iostream>
#include <assert.h>
#include <cstring>
using namespace std;

 void LabTest::print()const
{
	cout << "Name:" << name << endl
		<< "price:" << price << endl
		<< "time:" << time << endl;
}
const char* LabTest::getName()const
{
	return name;
}
double LabTest::getPrice()const
{
	return price;
}
double LabTest::getTime()const
{
	return time;
}

LabTest::~LabTest()
{
	delete[]name;
}
LabTest::LabTest(const char* name , double time, double price )
{
	this->price = price;
	this->time = time;
	this->name = new char[strlen(name) + 1];
	assert(name != NULL);
	strcpy(this->name, name);
}
LabTest::LabTest(const LabTest& other )
{
	this->price = other.price;
	this->time = other.time;
	this->name = new char[strlen(other.name) + 1];
	assert(name != NULL);
	strcpy(this->name, other.name);
}
LabTest& LabTest::operator=(const LabTest& other)
{
	if (this != &other)
	{
		delete[]name;
		this->price = other.price;
		this->time = other.time;
		this->name = new char[strlen(other.name) + 1];
		assert(name != NULL);
		strcpy(this->name, other.name);
	}
	return *this;
}

void LabTest::setName(const char* name)
{
	delete[]name;
	this->name = new char[strlen(name) + 1];
	assert(this->name != NULL);
	strcpy_s(this->name, strlen(name) + 1, name);
}
void LabTest::setPrice(double price)
{
	this->price = price;
}
void LabTest::setTime(double time)
{
	this->time = time;
}
