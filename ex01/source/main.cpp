#include <iostream>
#include <cctype>
#include <cstdlib>
#include <unistd.h>
#include "iter.hpp"
#include "color.h"

template <typename T>
void print(T const &elem)
{
	std::cout << elem << " ";
}

template <typename T>
void increment(T &elem)
{
	elem++;
}

template <typename T>
void decrement(T &elem)
{
	elem--;
}

void toUpper(std::string &s)
{
	for (size_t i = 0; i < s.size(); i++)
		s[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(s[i])));
}

void toLower(std::string &s)
{
	for (size_t i = 0; i < s.size(); i++)
		s[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(s[i])));
}

void toA(std::string &s)
{
	for (size_t i = 0; i < s.size(); i++)
		s[i] = 'A';
}

void testInt(void)
{
	std::cout << BYELLOW "\n=== TEST 1: int array ===" RESET << std::endl;
	int		ints[] = {1, 2, 3, 4, 5, 6, 7, 8 , 9, 10};
	size_t	intsLen = sizeof(ints) / sizeof(ints[0]);

	std::cout << LYELLOW << "Before: " << RESET;
	::iter(ints, intsLen, print<int>);
	std::cout << std::endl;

	::iter(ints, intsLen, increment<int>);
	std::cout << LGREEN << "After increment: " << RESET;
	::iter(ints, intsLen, print<int>);
	std::cout << std::endl;

	::iter(ints, intsLen, decrement<int>);
	std::cout << LGREEN << "After decrement: " << RESET;
	::iter(ints, intsLen, print<int>);
}

void testString(void)
{
	std::cout << BYELLOW "\n=== TEST 2: string array ===" RESET << std::endl;
	std::string	strs[] = {"Hello", "World", "This", "Is", "A", "Test"};
	size_t		strsLen = sizeof(strs) / sizeof(strs[0]);

	std::cout << LYELLOW << "Before: " << RESET;
	::iter(strs, strsLen, print<std::string>);
	std::cout << std::endl;

	::iter(strs, strsLen, toUpper);
	std::cout << LGREEN << "After toUpper: " << RESET;
	::iter(strs, strsLen, print<std::string>);
	std::cout << std::endl;

	::iter(strs, strsLen, toLower);

	std::cout << LGREEN << "After toLower: " << RESET;
	::iter(strs, strsLen, print<std::string>);
	std::cout << std::endl;
}

void testToA(void)
{
	std::cout << BYELLOW "\n=== TEST 3: toA ===" RESET << std::endl;
	std::string	strs[] = {"Hello", "World", "This", "Is", "A", "Test"};
	size_t		strsLen = sizeof(strs) / sizeof(strs[0]);
	std::cout << LYELLOW << "Before: " << RESET;
	::iter(strs, strsLen, print<std::string>);
	std::cout << std::endl;

	::iter(strs, strsLen, toA);
	std::cout << LGREEN << "After toA: " << RESET;
	::iter(strs, strsLen, print<std::string>);
	std::cout << std::endl;
}

int main(int argc, char** argv)
{
	srand(static_cast<unsigned int>(getpid() * time(NULL)));
	typedef void (*test_func)(void);
	static const test_func tests[] = {
		testInt,
		testString,
		testToA
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
