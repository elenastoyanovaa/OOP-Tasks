#include "Test.h"
#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;

void Test::print()const{
	LabTest::print();
	cout << "Up:" << up << endl
		<< "Down:" << down << endl;
}
Test::~Test(){}
Test::Test(const char* name, double price, double time,double up,double down):LabTest(name,price,time){
	this->up = up;
	this->down = down;
}
Test::Test(const Test& other):LabTest(other){
	up = other.up;
	down = other.down;
}
Test& Test::operator=(const Test& other)
{
	if (this != &other){
		LabTest::operator=(other);
		up = other.up;
		down = other.down;
	}
	return *this;
}

void Test::setUp(double up){
	this->up = up;
}
void Test::setDown(double down){
	this->down = down;
}
double Test::getUp()const
{
	return up;
}
double Test::getDown()const
{
	return down;
}