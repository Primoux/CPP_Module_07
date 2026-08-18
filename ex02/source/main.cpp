#include <iostream>
#include <cctype>
#include "color.h"
#include "Array.hpp"


int main(void)
{
	Array<int> test(755);
	int * a = new int();
	std::cout << *a << std::endl;
	delete a;
	return (0);
}
