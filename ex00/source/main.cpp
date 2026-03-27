#include <iostream>
#include "whatever.hpp"
#include "color.h"

int main(void)
{
	int a = 2;
	int b = 3;

	std::cout << BCYAN << "=== int ===" << RESET << std::endl;
	std::cout << LYELLOW << "Before swap: a = " << a << ", b = " << b << RESET << std::endl;
	::swap(a, b);
	std::cout << LGREEN << "After  swap: a = " << a << ", b = " << b << RESET << std::endl;
	std::cout << LBLUE << "min(a, b) = " << ::min(a, b) << RESET << std::endl;
	std::cout << LBLUE << "max(a, b) = " << ::max(a, b) << RESET << std::endl;

	std::cout << std::endl;

	std::string c = "string1";
	std::string d = "string2";

	std::cout << BCYAN << "=== std::string ===" << RESET << std::endl;
	std::cout << LYELLOW << "Before swap: c = " << c << ", d = " << d << RESET << std::endl;
	::swap(c, d);
	std::cout << LGREEN << "After  swap: c = " << c << ", d = " << d << RESET << std::endl;
	std::cout << LBLUE << "min(c, d) = " << ::min(c, d) << RESET << std::endl;
	std::cout << LBLUE << "max(c, d) = " << ::max(c, d) << RESET << std::endl;

	return (0);
}
