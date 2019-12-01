#ifndef SALDODIABASE_H
#define SALDODIABASE_H
#include <ostream>
#include <iostream>
class SaldoDiaBase
{
protected:
	int diaBase;
	double saldoDiaBase;

public:
	SaldoDiaBase(int diaBaseR = 0, double saldoDiaBaseR = 0) : diaBase(diaBaseR), saldoDiaBase(saldoDiaBaseR) { }

	int getDiaBase();
	double getSaldoDiaBase();
	void setDiaBase(int diaBase);
	void setSaldoDiaBase(double saldoSiaBase);

	//Write the member variables to stream objects
	friend std::ostream& operator << (std::ostream& out, const SaldoDiaBase& obj);

	//Read data from stream object and fill it in member variables
	friend std::istream& operator >> (std::istream& in, SaldoDiaBase& obj);
};

#endif
