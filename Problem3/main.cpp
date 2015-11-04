#include "Poly.h"
#include <iostream>
using namespace std;

int main()
{
	// poly = 8*x^4 + 10*x^3 + x^2 + 29*x + 19	
	int coefs[5] = { 19, 29, 1, 10, 8 };
	Poly poly(coefs, 5);
	cout << "Poly = " << endl;
	poly.print();
	cout << "Pnum(2.0) = " << poly.evaluate(2.0) << endl;
	return 0;
}