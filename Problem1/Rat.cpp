#include <iostream>
using namespace std;


struct rat
{
	int numer;
	int denom;
};
void sort(rat* num,int size){
	int i, j;
	rat temp;
	bool isSorted = true;
	for (i = 0; (i < size) && isSorted; i++)
	{
		isSorted = false;
		for (j = 0; j < size - 1; j++)
		{
			if (isLessThan(num[j],num[j+1]))
			{
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
				isSorted = true;
			}
		}
	}
	return;
}
int gcd(int a, int b)
{
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else
		{
			b = b - a;
		}

	}
	return a;
}

void makerat(rat& r, int a, int b)
{
	if (b == 0)
	{
		cout << "Vuvedete validen parametur" << endl;
	}
	else
	{
		if (a == 0)
		{
			r.numer = 0;
			r.denom = 1;
		}
		else
		{
			int k = gcd(abs(a), abs(b));
			if ((a > 0 && b > 0) || (a < 0 && b < 0))
			{
				r.numer = abs(a) / k;
				r.denom = abs(b) / k;
			}
			else
			{
				r.numer = -abs(a) / k;
				r.denom = abs(b) / k;
			}
		}
	}
}

int numer(const rat& r)
{
	return r.numer;
}

int denom(const rat& r)
{
	return r.denom;
}

void sumrat(rat& r, const rat& r1, const rat& r2)
{
	makerat(r, numer(r1) * denom(r2) + numer(r2)*denom(r1), denom(r1) * denom(r2));
}

void subrat(rat& r, const rat& r1, const rat& r2)
{
	makerat(r, numer(r1) * denom(r2) - numer(r2) * denom(r1), denom(r1) * denom(r2));
}

void multrat(rat& r, const rat& r1, const rat& r2)
{
	makerat(r, numer(r1) * numer(r2), denom(r1) * denom(r2));
}

void quotrat(rat& r, const rat& r1, const rat& r2)
{
	makerat(r, numer(r1) * denom(r2), denom(r1) * numer(r2));
}
void readrat(rat& r)
{
	cout << "r=";
	cin >> r.numer >> r.denom;
}

void printrat(const rat& r)
{
	cout << numer(r) << "/" << denom(r) << endl;
}

bool equal(int a, int b, int c, int d)
{
	if ((a == c) && (b == d))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isLessThan(const rat& r1, const rat& r2)
{
	if ((numer(r1) / denom(r1)) <= (numer(r2) / denom(r2)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	rat r1, r2, r;
	cout << "a=" << " " << "b=" << " " << "c=" << " " << "d=" << endl;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	makerat(r1, a, b);
	makerat(r2, c, d);
	if ((equal(a, b, c, d)) == true)
	{
		cout << "Chislata sa ravni!" << endl;
	}
	else
	{
		cout << "Chislata sa razlicni!" << endl;
	}
	if ((isLessThan(r1, r2) == true))
	{
		cout << "Izpulneno e!" << endl;
	}
	else
	{
		cout << "Ne e v sila!" << endl;
	}
	sumrat(r, r1, r2);
	cout << "suma:";
	printrat(r);
	cout << endl;
	subrat(r, r1, r2);
	cout << "razlika:";
	printrat(r);
	cout << endl;
	multrat(r, r1, r2);
	cout << "proizvedenie:";
	printrat(r);
	cout << endl;
	quotrat(r, r1, r2);
	cout << "chastno:";
	printrat(r);
	cout << endl;
	rat number[30];
	cout << "n=";
	int n;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		readrat(number[i]);
	}
	for (int i = 0; i<n; i++)
	{
		printrat(number[i]);
		cout << endl;
	}



	system("pause");
	return 0;
}

