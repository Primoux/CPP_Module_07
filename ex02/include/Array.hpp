#ifndef ARRAY_HPP



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

#include "Array.tpp"

#endif // !ARRAY_HPP