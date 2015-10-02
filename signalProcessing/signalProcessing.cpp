// signalProcessing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Signal.h"
#include "Noise.h"

int _tmain(int argc, _TCHAR* argv[])
{
	double srednia;
	double stdDev;

	Signal testSignal("test.txt");
	Noise testNoise(0.0, 2.0, 1000);

	testSignal.printValues();
	srednia = testSignal.mean();
	cout << srednia << endl;
	stdDev = testSignal.stdDeviation();
	cout << stdDev;
	testNoise.printValues();
	cout << testNoise.mean() << " " << testNoise.stdDeviation() << endl;
	cin.get();
	return 0;
}

