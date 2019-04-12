#include "Tramway.h"



Tramway::Tramway(int _street, int _startPoint, int _endPoint):street(_street),
															  startPoint(_startPoint),
															  endPoint(_endPoint)
{
}


Tramway::~Tramway()
{
}

int Tramway::getStart()
{
	return startPoint;
}

int Tramway::getEnd()
{
	return endPoint;
}

int Tramway::getStreet()
{
	return street;
}
