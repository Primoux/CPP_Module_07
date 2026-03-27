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

void toUpper(std::string &s)
{
	for (size_t i = 0; i < s.size(); i++)
		s[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(s[i])));
}

int main(void)
{
	int		ints[] = {1, 2, 3, 4, 5};
	size_t	intsLen = sizeof(ints) / sizeof(ints[0]);

	std::cout << BCYAN << "=== int[] ===" << RESET << std::endl;
	std::cout << LYELLOW << "Before: " << RESET;
	::iter(ints, intsLen, print<int>);
	std::cout << std::endl;

	::iter(ints, intsLen, increment<int>);

	std::cout << LGREEN << "After increment: " << RESET;
	::iter(ints, intsLen, print<int>);
	std::cout << std::endl;

	std::cout << std::endl;

	std::string strs[] = {"hello", "world", "42", "school"};
	size_t		strsLen = sizeof(strs) / sizeof(strs[0]);

	std::cout << BCYAN << "=== std::string[] ===" << RESET << std::endl;
	std::cout << LYELLOW << "Before: " << RESET;
	::iter(strs, strsLen, print<std::string>);
	std::cout << std::endl;

	::iter(strs, strsLen, toUpper);

	std::cout << LGREEN << "After toUpper: " << RESET;
	::iter(strs, strsLen, print<std::string>);
	std::cout << std::endl;

	return (0);
}
