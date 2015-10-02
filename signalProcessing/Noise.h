#pragma once
#include "signal.h"
#include <random>

class Noise :
	public Signal //dziedziczenie z klasy Sygnal
{
public:
	Noise(void);
	Noise(double mean, double deviation, int len);
	~Noise(void);
};

