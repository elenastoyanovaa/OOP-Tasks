#ifndef LAB_H
#define LAB_h
#include "Pack.h"
#include "Test.h"
#include <iostream>

class Laboratory {
public:
	Laboratory(LabTest** = NULL,size_t =0);
	Laboratory(const Laboratory& );
	Laboratory& operator=(const Laboratory& );
	virtual ~Laboratory();

	void print()const;

	void add(LabTest&);
	void remove();
	double totalPrice();
	LabTest& fastestTest();
private:
	LabTest** labT;
	size_t size;
};

#endif