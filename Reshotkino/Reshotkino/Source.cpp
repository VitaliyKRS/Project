#include <iostream>
#include "Town.h"


int main() {
	Town town;
	if (town.readFile("test3")) {
		std::cout << "File read successfully\n";
	};
	town.findEmpty();
	if (town.saveFile()) {
		std::cout << "File save successfully\n";
	};
	std::cin.get();
	return 0;
}