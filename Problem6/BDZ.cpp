#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;

class Ticket {
public:
	virtual int countPeople()
	{
		return 0;
	}
	virtual double getPrice()const
	{
		return this->price;
	}
	virtual ~Ticket()
	{
		delete[]start;
		delete[]end;
	}
	Ticket(const Ticket& other)
	{
		this->price = other.price;
		this->start = new char[strlen(other.start) + 1];
		assert(this->start);
		strcpy_s(this->start, strlen(other.start) + 1, other.start);
		this->end = new char[strlen(other.end) + 1];
		assert(this->end);
		strcpy_s(this->end, strlen(other.end) + 1, other.end);
	}
	Ticket& operator=(const Ticket& other){

		if (this != &other)
		{
			delete[]start;
			delete[]end;
			this->price = other.price;
			this->start = new char[strlen(other.start) + 1];
			assert(this->start);
			strcpy_s(this->start, strlen(other.start) + 1, other.start);
			this->end = new char[strlen(other.end) + 1];
			assert(this->end);
			strcpy_s(this->end, strlen(other.end) + 1, other.end);
		}
		return *this;
	}
	Ticket(double price, char* start, char* end)
	{
		this->price = price;
		this->start = new char[strlen(start) + 1];
		assert(this->start);
		strcpy_s(this->start, strlen(start) + 1, start);
		this->end = new char[strlen(end) + 1];
		assert(this->end);
		strcpy_s(this->end, strlen(end) + 1, end);
	}
	char* getStart()const
	{
		return this->start;
	}
	char* getEnd()const
	{
		return this->end;
	}
	virtual void print()const
	{
		cout << "Start:" << start << endl
			<< "End:" << end << endl
			<< "Price:" << price << endl;
	}
	virtual Ticket* clone(){
		return new Ticket(*this);
	}

protected:
	double price;
	char* start;
	char* end;

};

class Student : public Ticket {
public:
	virtual double getPrice()const
	{
		return (price*0.5);
	}
	virtual int countPeople()const
	{
		return 1;
	}

	virtual void print()const
	{
		Ticket::print();
		cout << "Discount price:" << getPrice() << endl;
	}

	Student(double price, char* start, char* end) :Ticket(price, start, end)
	{

	}


};

class Group : public Ticket {
public:
	virtual double getPrice()
	{
		return people*price*0.7;
	}
	virtual int countPeople()
	{
		return people;
	}

	virtual void print()
	{
		Ticket::print();
		cout << "Discount price:" << getPrice() << endl;
	}

	Group(double price, char* start, char* end, int people) :Ticket(price, start, end)
	{
		this->people = people;
	}
protected:
	int people;

};

class Train{
public:
	char* getStart()const
	{
		return this->start;
	}
	char* getEnd()const
	{
		return this->end;
	}
	int getCountTickets()const
	{
		return countTickets;
	}
	virtual double getPrice()const
	{
		double sum = 0;
		for (int i = 0; i < countTickets; i++)
		{
			sum += tickets[i]->getPrice();
		}
		return sum;
	}
	bool buyTicket(double price, size_t people = 1, char*type = "normal")//?
	{
		if (countTickets == 100)
		{
			return false;
		}
		else {
			if (people == 1 && !strcmp(type, "student"))
			{
				Student *ticket = new Student(price, start, end);
				this->tickets[countTickets++] = ticket;
			}
			else if (people > 1)
			{
				if (people >= 4)
				{
					Group *ticket = new Group(price, start, end, people);
					this->tickets[countTickets++] = ticket;
				}
				else {
					Ticket** ticket;
					for (int i = 0; i < people; i++)
					{
						ticket[i] = new Ticket(price, start, end);
						this->tickets[countTickets++] = ticket[i];
					}
				}
			}
			else {
				Ticket *ticket = new Ticket(price, start, end);
				tickets[countTickets++] = ticket;
			}
		}
	}
	virtual void print()const
	{
		cout << "Start:" << this->start << endl
			<< "End:" << this->end << endl
			<< "Price:" << this->getPrice() << endl
			<< "Tickets:" << Train::getCountTickets() << endl;
	}

	~Train()
	{
		delete[]start;
		delete[]end;
		if (tickets)
		{
			for (int i = 0; i < countTickets; i++)
			{
				delete[]tickets[i];
			}
		}
	}
	Train(const Train& other)
	{
		this->countTickets = other.countTickets;
		this->seatsTaken = other.seatsTaken;
		this->start = new char[strlen(start) + 1];
		assert(this->start);
		strcpy_s(this->start, strlen(start) + 1, start);
		this->end = new char[strlen(end) + 1];
		assert(this->end);
		strcpy_s(this->end, strlen(end) + 1, end);
		for (int i = 0; i < countTickets; i++)
		{
			this->tickets[i] = other.tickets[i]->clone();///ili?
		}

	}
	Train& operator=(const Train& other)
	{
		if (this != &other)
		{
			delete[]start;
			delete[]end;
			this->countTickets = other.countTickets;
			this->seatsTaken = other.seatsTaken;
			this->start = new char[strlen(start) + 1];
			assert(this->start);
			strcpy_s(this->start, strlen(start) + 1, start);
			this->end = new char[strlen(end) + 1];
			assert(this->end);
			strcpy_s(this->end, strlen(end) + 1, end);
			for (int i = 0; i < countTickets; i++)
			{
				this->tickets[i] = other.tickets[i]->clone();///ili?
			}
		}
		return *this;
	}
	Train(char* start, char* end)
	{
		this->countTickets = 0;
		this->seatsTaken = 0;
		this->start = new char[strlen(start) + 1];
		assert(this->start);
		strcpy_s(this->start, strlen(start) + 1, start);
		this->end = new char[strlen(end) + 1];
		assert(this->end);
		strcpy_s(this->end, strlen(end) + 1, end);
	}
private:
	Ticket* tickets[100];
	size_t countTickets;
	size_t seatsTaken;
	char* end;
	char* start;
};

int main()
{
	Train train("a", "b");
	train.buyTicket(4,1,"student");
	train.print();

	cout<<train.getPrice();

	return 0;
}