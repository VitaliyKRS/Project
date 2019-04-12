#pragma once
#include"Tramway.h"
#include<map>
#include<vector>
#include<memory>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>

class Town
{
	std::vector<std::unique_ptr<Tramway>> tramways;
	std::map<std::string, int> properties;
	int count_empty;
	std::string filename;
public:
	Town();
	~Town();
	bool readFile(std::string _file);
	void findEmpty();
	bool saveFile();
};

