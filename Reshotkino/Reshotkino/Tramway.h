#pragma once
class Tramway
{
	int street;
	int startPoint;
	int endPoint;
public:
	Tramway(int _street,int _startPoint,int _endPoint);
	~Tramway();
	int getStart();
	int getEnd();
	int getStreet();
};

