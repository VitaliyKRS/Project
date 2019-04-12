#include "Town.h"



Town::Town()
{
}


Town::~Town()
{
}

bool Town::readFile(std::string _file)
{
	filename = _file;
	std::ifstream file(_file + ".txt");
	if (!file.is_open())
	{
		std::cout << "Error open File\n";
		return false;
	}
	bool setProperties = true;
	int tempint;
	std::string tempstr;
	while (std::getline(file, tempstr)) {
		std::istringstream iss(tempstr);
		std::vector<int> tempv;
		while (iss >> tempint) {
			tempv.push_back(tempint);
		}
		if (setProperties) {
			properties.insert(std::make_pair("row", tempv.at(0)));
			properties.insert(std::make_pair("colum", tempv.at(1)));
			properties.insert(std::make_pair("way", tempv.at(2)));
		}
		else {
			tramways.push_back(std::make_unique<Tramway>(tempv.at(0), tempv.at(1), tempv.at(2)));
		}
		setProperties = false;
	}
	file.close();
	return true;
}

void Town::findEmpty()
{
	std::vector<std::vector<int>> townMap(properties.at("row"), std::vector<int>(properties.at("colum"), 0));
	for (auto &it : tramways) {
		for (int i = it->getStart() - 1; i <= it->getEnd() - 1; ++i) {
			townMap[it->getStreet() - 1][i] = 1;
		}
	}
	std::for_each(townMap.begin(), townMap.end(), [&](const std::vector<int>&v)
	{
		count_empty += std::count_if(v.begin(), v.end(), [](int j) {
			return j == 0;
		});
	});
}

bool Town::saveFile()
{
	std::ofstream file(filename + "-out.txt");
	if (!file.is_open())
	{
		std::cout << "Error open File\n";
		return false;
	}
	file << count_empty;
	file.close();
	return true;
}
