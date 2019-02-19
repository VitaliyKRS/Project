#pragma once
#include "tinyxml2.h"
#include <queue>
#include <vector>
#include <sstream>


class XML
{
	tinyxml2::XMLDocument openDoc, saveDoc;
	std::queue<int> intervals;

public:
	XML();
	void Save(std::vector<int> _first, std::vector<int> _second); //Save prime in xml
	bool LoadXMl();
	bool SaveXML();


	std::queue<int> ReadIntervals();
	virtual ~XML();
};


