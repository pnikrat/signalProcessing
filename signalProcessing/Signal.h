#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<math.h>

using namespace std;

class Signal
{
protected:
	double *signal_samples; //wsk na dynamiczna tablice
	int length; //dlugosc sygnalu, tj. ilosc probek

public:
	Signal(void);
	Signal(int len);
	Signal(const char* pathname);
	virtual ~Signal(void);

	double * getSamples(void);
	int getLength(void);
	void printValues(void);
	double mean(void);
	double stdDeviation(void);
	Signal convolution(Signal otherSignal);
};

