#ifndef SOME_H
#define SOME_H
#include "LabTest.h"

class Test:public LabTest {

public:
	virtual void print()const;

	virtual ~Test();
	Test(const char* = "", double =0, double =0,double =0,double =0);
	Test(const Test&);
	Test& operator=(const Test&);

	void setUp(double);
	void setDown(double);
	double getUp()const;
	double getDown()const;

private:
	double up;
	double down;

};

#endif