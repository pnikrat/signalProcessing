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
	Signal(const char* pathname);
	~Signal(void);

	double * getSamples(void);
	int getLength(void);
	void printValues(void);
	double mean(void);
	double stdDeviation(void);
};

