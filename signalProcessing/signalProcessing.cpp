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
	Signal testSignal2("test2.txt");
	
	Noise testNoise(0.0, 2.0, 1000);

	testSignal.printValues();
	testSignal2.printValues();
	srednia = testSignal.mean();
	cout << srednia << endl;
	stdDev = testSignal.stdDeviation();
	cout << stdDev << endl;
	//testNoise.printValues();
	//cout << testNoise.mean() << " " << testNoise.stdDeviation() << endl;

	Signal result = testSignal.convolution(testSignal2);
	result.printValues();
	cin.get();
	return 0;
}

