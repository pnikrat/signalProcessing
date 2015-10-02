#include "stdafx.h"
#include "Signal.h"


Signal::Signal(void)
{
}

Signal::Signal(const char* pathname)
{
	/*Odczytanie dlugosci sygnalu z pliku */
	ifstream readStream; 
	readStream.open(pathname, ios::in);
	double temp;
	int count = 0;
	while (readStream >> temp)
		count++;
	readStream.close();
	length = count; //przypisanie dlugosci sygnalu

	/*Jezeli powiodlo sie - wstaw wartosci do tablicy */
	if (count)
	{
		readStream.open(pathname, ios::in);
		signal_samples = new double [count];
		for (int i = 0 ; i < count ; i++)
		{
			readStream >> *(signal_samples + i);
		}
	}
	
}


Signal::~Signal(void)
{
	delete [] signal_samples;
}

double * Signal::getSamples(void)
{
	return signal_samples;
}

int Signal::getLength(void)
{
	return length;
}

void Signal::printValues(void)
{
	for (int i = 0 ; i < length ; i++)
	{
		cout << "Signal value[" << i << "]: " << *(signal_samples + i) << endl;
	}
}

double Signal::mean(void)
{
	double suma = 0.0;
	
	for (int i = 0 ; i < length ; i++)
	{
		suma += *(signal_samples + i);
	}

	return suma / length;
}

double Signal::stdDeviation(void)
{
	double srednia = this->mean();
	double suma = 0.0;
	double square;

	for (int i = 0 ; i < length ; i++)
	{
		square = pow( *(signal_samples + i) - srednia, 2.0);
		suma += square;
	}

	return sqrt(suma / length);
}
