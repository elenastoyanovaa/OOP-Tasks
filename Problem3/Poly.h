#ifndef POLY_H
#define POLY_H

class Poly
{
private:
	int degree;
	int* coefs;
public:
	int evaluate(double )const;
	void print()const;
	Poly(int* , int );
	~Poly();
	Poly();
	void setCoef(int , int );
	int getCoef(int )const;
};

#endif