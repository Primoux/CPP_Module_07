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
	std::cout << BYELLOW "\n=== TEST 1: int[] ===" RESET << std::endl;
	int		ints[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	size_t	len = sizeof(ints) / sizeof(ints[0]);

	std::cout << LYELLOW << "Before: " << RESET;
	::iter(ints, len, print<int>);
	std::cout << std::endl;

	::iter(ints, len, increment<int>);
	std::cout << LGREEN << "After increment: " << RESET;
	::iter(ints, len, print<int>);
	std::cout << std::endl;

	::iter(ints, len, decrement<int>);
	std::cout << LGREEN << "After decrement: " << RESET;
	::iter(ints, len, print<int>);
	std::cout << std::endl;
}

void test_string_array(void)
{
	std::cout << BYELLOW "\n=== TEST 2: std::string[] ===" RESET << std::endl;
	std::string	strs[] = {"hello", "world", "42", "school"};
	size_t		len = sizeof(strs) / sizeof(strs[0]);

	std::cout << LYELLOW << "Before: " << RESET;
	::iter(strs, len, print<std::string>);
	std::cout << std::endl;

	::iter(strs, len, toUpper);
	std::cout << LGREEN << "After toUpper: " << RESET;
	::iter(strs, len, print<std::string>);
	std::cout << std::endl;

	::iter(strs, len, toLower);
	std::cout << LGREEN << "After toLower: " << RESET;
	::iter(strs, len, print<std::string>);
	std::cout << std::endl;
}

void test_const_array(void)
{
	std::cout << BYELLOW "\n=== TEST 3: const int[] ===" RESET << std::endl;
	int const	consts[] = {10, 20, 30, 40};
	size_t		len = sizeof(consts) / sizeof(consts[0]);

	std::cout << LYELLOW << "Read only: " << RESET;
	::iter(consts, len, print<int>);
	std::cout << std::endl;
}

int main(void)
{
	test_int_array();
	test_string_array();
	test_const_array();
	return (0);
}
