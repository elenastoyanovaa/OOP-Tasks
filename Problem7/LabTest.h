#ifndef LABT_H
#define LABT_H

class LabTest {
public:

	virtual void print()const;
	const char* getName()const;
	virtual double getPrice()const;
	virtual double getTime()const;

	virtual ~LabTest();
	LabTest(const char* = "", double = 0, double = 0);
	LabTest(const LabTest&);
	LabTest& operator=(const LabTest&);

	void setName(const char*);
	void setPrice(double);
	void setTime(double);

	virtual LabTest* clone()const
	{
		return new LabTest(*this);
	}

private:
	char* name;
	double price;
	double time;
};

#endif