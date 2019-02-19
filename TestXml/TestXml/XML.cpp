#include "XML.h"



XML::XML()
{
}

void XML::Save(std::vector<int> _first, std::vector<int> _second)
{
	std::stringstream ss;
	char buff[400]{};
	tinyxml2::XMLNode * pRoot = saveDoc.NewElement("root");
	saveDoc.InsertFirstChild(pRoot);
	tinyxml2::XMLElement * pElement = saveDoc.NewElement("primes");
	for (const auto &it : _first) {
		ss << it;
	}
	for (const auto &it : _second) {
		ss << it;
	}
	for (int i = 0, j = 3; i < 400; ++i, j += 4) {
		if (buff[i] != ' ') ss >> buff[i];
		if (j < 400) buff[j] = ' ';
	}
	pElement->SetText(buff);
	pRoot->InsertEndChild(pElement);
	SaveXML();
}

bool XML::LoadXMl()
{
	tinyxml2::XMLError eResult = openDoc.LoadFile("../TestXml/TaskXML.xml");
	if (eResult != tinyxml2::XML_SUCCESS) {
		return false;
	}
	return true;
}

bool XML::SaveXML()
{
	tinyxml2::XMLError eResult = saveDoc.SaveFile("../TestXml/SavedPrimes.xml");
	if (eResult != tinyxml2::XML_SUCCESS) {
		return false;
	}
	return true;
}


std::queue<int> XML::ReadIntervals()
{
	tinyxml2::XMLElement * pRoot = openDoc.FirstChildElement("root");

	tinyxml2::XMLElement * Intervals, *Interval;
	Intervals = pRoot->FirstChildElement("intervals");

		for (Interval = Intervals->FirstChildElement("interval"); Interval; Interval = Interval->NextSiblingElement("interval")) {
		tinyxml2::XMLElement * hight, *low;
		low = Interval->FirstChildElement("low");
		hight = Interval->FirstChildElement("high");
		int low_value = 0, high_value = 0;
		low->QueryIntText(&low_value);
		intervals.push(low_value);
		hight->QueryIntText(&high_value);
		intervals.push(high_value);
		}
		return intervals;
}

XML::~XML()
{
}
