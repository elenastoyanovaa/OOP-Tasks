#include <iostream>
#include <assert.h>
#include "Poly.h"
using namespace std;

int Poly::evaluate(double x)const
{
	double sum = 0.0;
	double xPow = 1.0;
	if (coefs)
		for (int i = 0; i<degree; i++)
		{
			sum += xPow*coefs[i];
			xPow *= x;
		}

	return sum;
}
void Poly::print()const
{
	cout << coefs[degree - 1] << "x^" << degree - 1;
	for (int i = degree - 2; i >= 0; i--)
	{
		cout << " + " << coefs[i] << "x^" << i;
	}
}
Poly::Poly(int* coefs, int degree)
{
	this->degree = degree;
	this->coefs = new int[degree];
	for (int i = 0; i<degree; i++)
		this->coefs[i] = coefs[i];
}
Poly::~Poly()
{
	delete[]coefs;
}
Poly::Poly()
{
	this->degree = 0;
	this->coefs = new int[1];
	coefs[0] = 0;
}
void Poly::setCoef(int degree, int newCoef)
{
	if (degree <= this->degree) coefs[degree] = newCoef;
	else
		cout << "The polynomial has e lower degree!" << endl;
}
int Poly::getCoef(int degree)const
{
	return coefs[degree];
}