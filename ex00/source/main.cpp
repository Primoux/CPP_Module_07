#include <iostream>
#include "whatever.hpp"
#include "color.h"

int main( void )
{
	int a = 2;
	int b = 3;

	std::cout << BPURPLE << "a = " << a << ", b = " << b << std::endl;

	::swap( a, b );
	std::cout << BPURPLE << "a = " << a << ", b = " << b << std::endl;
	std::cout << BGREEN << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << BRED << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "string1";
	std::string d = "string2";

	std::cout << BPURPLE << "c = " << c << ", d = " << d << std::endl;

	::swap(c, d);
	std::cout << BPURPLE << "c = " << c << ", d = " << d << std::endl;
	std::cout << BGREEN << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << BRED << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}
