#include "Primes.h"



Primes::Primes()
{
	mXml.LoadXMl();
}


Primes::~Primes()
{
	mXml.Save(First_interval, Second_interval);
}

bool Primes::setInterval()
{
	auto que = mXml.ReadIntervals();
	if (que.empty()) {
		return false;
	}
	firstlow = que.front();
	que.pop();
	firsthigh = que.front();
	que.pop();
	secondlow = que.front();
	que.pop();
	secondhigh = que.front();
	que.pop();
	return true;
}

void Primes::startThread()
{
	std::thread t1(&Primes::FindPrimes, this,firstlow,firsthigh,std::ref(First_interval));
	std::thread t2(&Primes::FindPrimes, this,secondlow,secondhigh,std::ref(Second_interval));
	t1.join();
	t2.join();
}

bool Primes::TestVectorsPrimes()
{
	if (First_interval.empty() || Second_interval.empty()) {
		return false;
	}
	return (checkPrime(First_interval) && checkPrime(Second_interval)) == true ? true : false;
}

bool Primes::checkPrime(std::vector<int>& _intervl)
{
	for (const auto& it : _intervl) {
		for (int j = 2; j <= it / 2; ++j)
		{
			if (it % j == 0)
			{
				return false;
			}
		}
	}
	return true;
}

void Primes::FindPrimes(int _low, int _high, std::vector<int>& _inrevl)
{
	for (int i = _low; i < _high; ++i)
	{
		bool isprime = true;
		for (int j = 2; j <= i / 2; ++j)
		{
			if (i % j == 0)
			{
				isprime = false;
				break;
			}
		}

		if (isprime) {
			_inrevl.push_back(i);
		}
	}
}
