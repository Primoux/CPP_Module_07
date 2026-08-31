#include <iostream>
#include <cctype>
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

void test_int_array(void)
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

void test_string_array(void)
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

int main(void)
{
	test_int_array();
	test_string_array();
	return (0);
}
