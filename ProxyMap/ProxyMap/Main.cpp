#include "ProxyMap.h"
#include "Auditor.h"
#include <conio.h>


int main() {
	ProxyMap<int,char> b(std::make_shared<ReadEdit>());
	b.write(std::make_pair(1,'a'));
	b.readKey(1);
	_getch();
	return 0;
}
