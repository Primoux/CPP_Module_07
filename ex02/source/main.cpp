#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unistd.h>
#include "Array.hpp"

static void	test_basic_operations(void)
{
	std::cout << BYELLOW "=== TEST 1: Basic operations ===" RESET << std::endl;
	Array<int> numbers(10);
	for (unsigned int i = 0; i < 10; i++)
		numbers[i] = rand() % 15;
	std::cout << numbers << std::endl;
}

static void	test_copy_constructor(void)
{
	std::cout << BYELLOW "\n=== TEST 2: Copy constructor ===" RESET << std::endl;
	Array<int> orig(5);
	for (unsigned int i = 0; i < 5; i++)
		orig[i] = i + rand() % 15;
	std::cout << "Original: " << orig << std::endl;
	{
		Array<int> tmp = orig;
		Array<int> test(tmp);
		std::cout << "Copy: " << tmp << std::endl;
	}
	std::cout << "After scope (destructors called)" << std::endl;
}

static void	test_values_integrity(void)
{
	std::cout << BYELLOW "\n=== TEST 3: Values integrity ===" RESET << std::endl;
	Array<int> arr(5);
	int* mirror = new int[5];
	for (unsigned int i = 0; i < 5; i++)
	{
		const int value = i + rand() * 15;
		arr[i] = value;
		mirror[i] = value;
	}
	bool ok = true;
	for (unsigned int i = 0; i < 5; i++)
	{
		if (mirror[i] != arr[i])
			ok = false;
	}
	std::cout << (ok ? "All values match!" : "Values mismatch!") << std::endl;
	delete[] mirror;
}

static void	test_out_of_bounds(void)
{
	std::cout << BYELLOW "\n=== TEST 4: Out of bounds access ===" RESET << std::endl;
	Array<int> arr(5);
	try
	{
		arr[-2] = rand() % 15;
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << "Caught: " << e.what() << '\n';
	}
	try
	{
		arr[5] = rand() % 10;
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << "Caught: " << e.what() << '\n';
	}
}

static void	test_assignment_operator(void)
{
	std::cout << BYELLOW "\n=== TEST 5: Assignment operator ===" RESET << std::endl;
	Array<int> a(5);
	Array<int> b(3);
	for (unsigned int i = 0; i < 5; i++)
		a[i] = i + rand() % 15;
	for (unsigned int i = 0; i < 3; i++)
		b[i] = i + rand() % 15;
	std::cout << "a before: " << a << std::endl;
	std::cout << "b before: " << b << std::endl;
	a = b;
	std::cout << "a after: " << a << std::endl;
}

static void	test_deep_copy(void)
{
	std::cout << BYELLOW "\n=== TEST 6: Deep copy check ===" RESET << std::endl;
	Array<int> orig(4);
	for (unsigned int i = 0; i < 4; i++)
		orig[i] = i + rand() % 15;
	std::cout << "orig: " << orig << std::endl;
	Array<int> copy = orig;
	std::cout << "copy: " << copy << std::endl;
	orig[0] = 999;
	std::cout << "After orig[0] = 999:" << std::endl;
	std::cout << "orig: " << orig << std::endl;
	std::cout << "copy: " << copy << std::endl;
	if (copy[0] == 999)
		std::cout << "WARNING: Shallow copy!" << std::endl;
	else
		std::cout << "Good: Deep copy!" << std::endl;
}

static void	test_different_types(void)
{
	std::cout << BYELLOW "\n=== TEST 7: Different types ===" RESET << std::endl;
	Array<float> floats(3);
	floats[0] = 3.14f;
	floats[1] = 2.71f;
	floats[2] = 1.41f;
	std::cout << "Float array: " << floats << std::endl;

	Array<std::string> strings(3);
	strings[0] = "Hello";
	strings[1] = "World";
	strings[2] = "Test";
	std::cout << "String array: " << strings << std::endl;
}

static void	test_edge_cases(void)
{
	std::cout << BYELLOW "\n=== TEST 8: Edge case ===" RESET << std::endl;
	Array<int> empty(0);
	std::cout << "Empty array size: " << empty.size() << std::endl;
	std::cout << "Empty array: " << empty << std::endl;

	Array<int> single(1);
	single[0] = 42;
	std::cout << "Single element: " << single << std::endl;
}

static void	test_non_const_access(void)
{
	std::cout << BYELLOW "\n=== TEST 9: Non-const operator[] ===" RESET << std::endl;
	Array<int> arr(3);
	arr[0] = rand() % 15;
	arr[1] = rand() % 15;
	arr[2] = rand() % 15;
	std::cout << "Original: " << arr << std::endl;
	arr[1] = 999;
	std::cout << "After arr[1] = 999: " << arr << std::endl;
	std::cout << "Accessing arr[1]: " << arr[1] << std::endl;
}

static void	test_destructor(void)
{
	std::cout << BYELLOW "\n=== TEST 10: Destructor check ===" RESET << std::endl;
	std::cout << "Creating temporary..." << std::endl;
	{
		Array<int> temp(2);
		temp[0] = 100;
		temp[1] = 200;
		std::cout << "Temp: " << temp << std::endl;
	}
	std::cout << "Destroyed" << std::endl;
}

static void test_string(void)
{
	std::cout << BYELLOW "\n=== TEST 11: String test ===" RESET << std::endl;
	try
	{
		Array<std::string> arr(3);
		arr[0] = "Hello";
		arr[1] = "World";
		arr[2] = "Test";
		std::cout << "String array: " << arr << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << BRED "Exception caught: " RESET<< e.what() << std::endl;
	}
}

static void test_bad_alloc(void)
{
	std::cout << BYELLOW "\n=== TEST 12: Bad allocation test ===" RESET << std::endl;
	try
	{
		Array<int> arr(1);
		arr[0] = 42;
	}
	catch (const std::exception& e)
	{
		std::cerr << BRED "Exception caught: " RESET << e.what() << std::endl;
	}
}

int main(int argc, char** argv)
{
	srand(static_cast<unsigned int>(getpid() * time(NULL)));
	typedef void (*test_func)(void);
	static const test_func tests[] = {
		test_basic_operations,
		test_copy_constructor,
		test_values_integrity,
		test_out_of_bounds,
		test_assignment_operator,
		test_deep_copy,
		test_different_types,
		test_edge_cases,
		test_non_const_access,
		test_destructor,
		test_string,
		test_bad_alloc
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
