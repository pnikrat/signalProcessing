#include "stdafx.h"
#include "Noise.h"


Noise::Noise(void)
{
}

Noise::Noise(double mean, double deviation, int len)
{
	default_random_engine generator; //generator liczb losowych
	normal_distribution<double> rozklad_normalny(mean, deviation); //gaussowski szum o wart sredniej mean i odch. std. deviation
	length = len; // ilosc probek
	signal_samples = new double [length]; //init dynamiczny

	for (int i = 0 ; i < length ; i++)
	{
		*(signal_samples + i) = rozklad_normalny(generator);
	}
}

