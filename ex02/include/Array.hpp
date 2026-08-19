#ifndef ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
  private:
	T *_array;
	size_t _size;

  public:
	// CONSTRUCTOR
	Array();
	Array(unsigned int n);
	~Array();
	Array(Array const &original);

	// OPERATOR
	Array &operator=(Array const &other);
	T& operator[](unsigned int i);
	const T& operator[](unsigned int i) const;
	// FUNCTION MEMBER
	size_t size() const;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr);
#include "Array.tpp"

#endif // !ARRAY_HPP