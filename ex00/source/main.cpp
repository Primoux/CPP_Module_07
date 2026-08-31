#include <iostream>
#include <string>
#include "whatever.hpp"
#include "color.h"

void test_min(void)
{
	std::cout << BYELLOW "\n=== TEST 1: min ===" RESET << std::endl;
	int a = 2;
	int b = 3;
	std::cout << BGREEN << "min(" << a << ", " << b << ") = " << ::min(a, b) << RESET << std::endl;
}

void test_max(void)
{
	std::cout << BYELLOW "\n=== TEST 2: max ===" RESET << std::endl;
	int a = 2;
	int b = 3;
	std::cout << BRED << "max(" << a << ", " << b << ") = " << ::max(a, b) << RESET << std::endl;
}

void test_swap(void)
{
	std::cout << BYELLOW "\n=== TEST 3: swap ===" RESET << std::endl;
	int a = 2;
	int b = 3;
	std::cout << BBLUE << "Before swap: a = " << a << ", b = " << b << RESET << std::endl;
	::swap(a, b);
	std::cout << BBLUE << "After swap: a = " << a << ", b = " << b << RESET << std::endl;
}

void test_combined(void)
{
	std::cout << BYELLOW "\n=== TEST 4: all tests ===" RESET << std::endl;
	std::string a = "string1";
	std::string b = "string2";
	std::cout << BBLUE << "Before swap: a = " << a << ", b = " << b << RESET << std::endl;
	std::cout << BGREEN << "min(" << a << ", " << b << ") = " << ::min(a, b) << RESET << std::endl;
	std::cout << BRED << "max(" << a << ", " << b << ") = " << ::max(a, b) << RESET << std::endl;
	::swap(a, b);
	std::cout << BBLUE << "After swap: a = " << a << ", b = " << b << RESET << std::endl;
	std::cout << BGREEN << "min(" << a << ", " << b << ") = " << ::min(a, b) << RESET << std::endl;
	std::cout << BRED << "max(" << a << ", " << b << ") = " << ::max(a, b) << RESET << std::endl;
}

int main( void )
{
	test_min();
	test_max();
	test_swap();
	test_combined();
	return 0;
}
