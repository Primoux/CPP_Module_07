#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include "whatever.hpp"
#include "color.h"

void testMin(void)
{
	std::cout << BYELLOW "\n=== TEST 1: min ===" RESET << std::endl;
	int a = rand() % 100;
	int b = rand() % 100;
	std::cout << BGREEN << "min(" << a << ", " << b << ") = " << ::min(a, b) << RESET << std::endl;
}

void testMax(void)
{
	std::cout << BYELLOW "\n=== TEST 2: max ===" RESET << std::endl;
	int a = rand() % 100;
	int b = rand() % 100;
	std::cout << BRED << "max(" << a << ", " << b << ") = " << ::max(a, b) << RESET << std::endl;
}

void testSwap(void)
{
	std::cout << BYELLOW "\n=== TEST 3: swap ===" RESET << std::endl;
	int a = rand() % 100;
	int b = rand() % 100;
	std::cout << BBLUE << "Before swap: a = " << a << ", b = " << b << RESET << std::endl;
	::swap(a, b);
	std::cout << BBLUE << "After swap: a = " << a << ", b = " << b << RESET << std::endl;
}

void testCombinedString(void)
{
	std::cout << BYELLOW "\n=== TEST 4: all tests combined string ===" RESET << std::endl;
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

void testCombinedInt(void)
{
	std::cout << BYELLOW "\n=== TEST 5: all tests combined int ===" RESET << std::endl;
	int a = rand() % 100;
	int b = rand() % 100;
	std::cout << BBLUE << "Before swap: a = " << a << ", b = " << b << RESET << std::endl;
	std::cout << BGREEN << "min(" << a << ", " << b << ") = " << ::min(a, b) << RESET << std::endl;
	std::cout << BRED << "max(" << a << ", " << b << ") = " << ::max(a, b) << RESET << std::endl;
	::swap(a, b);
	std::cout << BBLUE << "After swap: a = " << a << ", b = " << b << RESET << std::endl;
	std::cout << BGREEN << "min(" << a << ", " << b << ") = " << ::min(a, b) << RESET << std::endl;
	std::cout << BRED << "max(" << a << ", " << b << ") = " << ::max(a, b) << RESET << std::endl;
}

int main(int argc, char** argv)
{
	srand(static_cast<unsigned int>(getpid() * time(NULL)));
	typedef void (*test_func)(void);
	static const test_func tests[] = {
		testMin,
		testMax,
		testSwap,
		testCombinedString,
		testCombinedInt
	};
	const int num_tests = sizeof(tests) / sizeof(tests[0]) + 1;

	if (argc == 1)
	{
		std::cout << BYELLOW "=== Running all tests ===" RESET << std::endl;
		for (int i = 0; i < num_tests - 1; i++)
			tests[i]();
		return 0;
	}
	std::cout << BYELLOW "=== Running selected tests ===" RESET << std::endl;
	for (int i = 1; i < argc; i++)
	{
		int test_num = atoi(argv[i]);
		if (test_num > 0 && test_num < num_tests)
			tests[test_num - 1]();
		else
			std::cerr << BRED "Unknown test: " RESET << test_num << std::endl;
	}

	return 0;
}

