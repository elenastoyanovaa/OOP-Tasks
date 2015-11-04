#include "Laboratory.h"
#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

Laboratory::Laboratory(LabTest** labT,size_t size){
	this->size = size;
	this->labT = new LabTest*[size];
	for (int i = 0; i < size; i++)
	{
		labT[i] = labT[i]->clone();
	}
}
Laboratory::Laboratory(const Laboratory& other){
	this->labT = new LabTest*[other.size];
	this->size = other.size;
	for (int i = 0; i < other.size; i++)
	{
		labT[i] = other.labT[i]->clone();
	}
}
Laboratory& Laboratory::operator = (const Laboratory& other){
	if (this != &other){
		for (int i = 0; i < size; i++)
		{
			delete[] labT[i];
		}
		delete[]labT;
		this->labT = new LabTest*[other.size];
		this->size = other.size;
		for (int i = 0; i < other.size; i++)
		{
			labT[i] = other.labT[i];
		}
	}
	return *this;
}
Laboratory::~Laboratory()
{
	for (int i = 0; i < size; i++)
	{
		delete[] labT[i];
	}
	delete[]labT;
}

void Laboratory::print()const{
	for (int i = 0; i < size; i++)
	{
		labT[i]->print();
	}
}

void Laboratory::add(LabTest& newOne){

	LabTest** temp = new LabTest*[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = this->labT[i];
	}
	delete[] this->labT;
	this->labT = temp;
	labT[size++] = newOne.clone();
}
void Laboratory::remove(){
	LabTest** temp;
	temp = new LabTest*[size-1];
	size--;
	for (int i = 0; i < size-1; i++){
		temp[i] = labT[i+1]->clone();
	}
	for (int i = 0; i < size; i++)
	{
		delete[] labT[i];
	}
	delete[]this->labT;
	labT = temp;



}
double Laboratory::totalPrice(){
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += labT[i]->getPrice();
	}
	return sum;
}
LabTest& Laboratory::fastestTest(){
	double fastest=labT[0]->getTime();

	for (int i = 0; i < size; i++)
	{
		if (fastest>labT[i]->getTime()){
			fastest = labT[i]->getTime();
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (fastest==labT[i]->getTime()){
			return *labT[i];
		}
	}

}
int main(){

	LabTest* tst[3];
	Test s, n;
	Pack p("Pack", 1, 2);
	tst[0] = &s;
	tst[1] = &p;
	p.addTest(tst[0]);
	p.addTest(tst[1]);
	tst[2] = &p;
	for (int i = 0; i < 3; i++)
	{
		cout << i << endl;
		tst[i]->print();
	}

	return 0;
}