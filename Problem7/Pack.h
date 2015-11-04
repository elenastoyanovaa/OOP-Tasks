#ifndef SOMET_H
#define SOMET_H
#include "Test.h"

class Pack:public LabTest {

public:
	Pack(const char* ="",double =0, double =0);
	~Pack();
	Pack(const Pack& );
	Pack& operator=(const Pack& );

	virtual double getPrice()const;
	virtual double getTime()const;
	virtual void print()const;

	void addTest(LabTest* newOne);


private:
	LabTest** t;
	size_t count;

};

#endif