#include "pch.h"
#include "Primes.h"
#include "XML.h"


class TestClassPrimes :public ::testing::Test {
public:
	Primes prime;
};

TEST_F(TestClassPrimes, SetIntrval) { // This test checks whether intervals were correctly calculated.
	ASSERT_TRUE(prime.setInterval());
}

TEST_F(TestClassPrimes, TestAllPrimeInVector) { //This test checks whether prime numbers are correctly written to the container.
	prime.setInterval();
	prime.startThread();
	ASSERT_TRUE(prime.TestVectorsPrimes());
}

