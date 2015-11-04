#include "Test.h"
#include "Pack.h"
#include <iostream>
#include <assert.h>
#include <cstring>
using namespace std;

void Pack::print()const
{
	for (int i = 0; i < count; i++)
	{
		t[i]->print();
	}
}
double Pack::getPrice()const
{
	double result;
	for (int i = 0; i < count; i++)
	{
		result += t[i]->getPrice();
	}
	return 0.9*result;
}
double Pack::getTime()const
{
	if (!count)
		return 0;

	double max=t[0]->getTime();
	
	for (int i = 0; i < count; i++)
	{
		if (max < t[i]->getTime())
		{
			max = t[i]->getTime();
		}
	}
	return max;
}

Pack::~Pack()
{
	for (int i = 0; i < count; i++)
	{
		delete[] t[i];
	}
	delete[]t;
}
Pack::Pack(const char* name,double price,double time) :LabTest(name,price,time), t(NULL)
{
	this->count = 0;
}
Pack::Pack(const Pack& other) :LabTest(other)
{
	this->t = new LabTest*[other.count];
	this->count = other.count;
	for (int i = 0; i < other.count; i++)
	{
		t[i] = other.t[i]->clone();
	}
}
Pack& Pack::operator=(const Pack& other)
{
	if (this != &other)
	{
		delete[]t;
		this->t = new LabTest*[other.count];
		this->count = other.count;
		for (int i = 0; i < other.count; i++)
		{
			t[i] = other.t[i];
		}
	}
	LabTest::operator=(other);
	return *this;
}
void Pack::addTest(LabTest* newOne)
{
	
	LabTest** temp = new LabTest*[count + 1];
	for (int i = 0; i < count; i++)
	{
		temp[i] = this->t[i];
	}
	delete[] this->t;
	this->t = temp;
	t[count] = newOne->clone();
	++count;

}