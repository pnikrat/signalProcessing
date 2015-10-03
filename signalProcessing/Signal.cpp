#include "stdafx.h"
#include "Signal.h"


Signal::Signal()
{
}

Signal::Signal(int len)
{
	length = len;
	signal_samples = new double[length];
}

Signal::Signal(const char* pathname)
{
	/*Odczytanie dlugosci sygnalu z pliku */
	fstream readStream; 
	int count = 0;

	readStream.open(pathname, ios::in);
	if (readStream.is_open() )
	{
		double temp;
		
		while (readStream >> temp)
			count++;
		length = count; //przypisanie dlugosci sygnalu
	}
	readStream.close();

	readStream.open(pathname, ios::in);
	/*Jezeli powiodlo sie - wstaw wartosci do tablicy */
	if (readStream.is_open())
	{
		signal_samples = new double [count];

		for (int i = 0 ; i < count ; i++)
		{
			readStream >> *(signal_samples + i);
		}		
	}
	readStream.close();
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

Signal Signal::convolution(Signal otherSignal) //x1 * x2 gdzie x2 to otherSignal
{
	static Signal output = Signal(length + otherSignal.getLength() - 1); //konstruktor Signal(int len)

	for (int i = 0 ; i < output.getLength() ; i++)
		*(output.getSamples() + i) = 0;

	for (int i = 0 ; i < output.getLength() ; i++)
	{
		for (int j = 0 ; j <= i ; j++)
		{
			if ( (j < length) && ( (i-j) < otherSignal.getLength()) )
				*(output.getSamples() + i) += ((*(signal_samples + j)) * (*(otherSignal.getSamples() + i - j)));
		}
	}
	return output;
}