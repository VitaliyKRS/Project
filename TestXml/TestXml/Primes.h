#pragma once
#include <vector>
#include <sstream>
#include <thread>
#include "XML.h"

class Primes
{
	int firstlow, firsthigh;   //Intervals
	int secondlow, secondhigh; //Intervals
	std::vector<int> First_interval;	//Container for storing primes read from the first interval
	std::vector<int> Second_interval;	//Container for storing primes read from the second interval
	XML mXml;
public:

	Primes();
	~Primes();

	bool setInterval();
	void startThread();  //Function that starts threads to fill containers

	//===========For UnitTest==============
	bool TestVectorsPrimes();
	bool checkPrime(std::vector<int>& _intervl);

private:
	void FindPrimes(int _low, int _high, std::vector<int>& _inrevl);
};


