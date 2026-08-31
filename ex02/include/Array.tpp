
#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "color.h"

template<typename T>
Array<T>::Array() :  _array(NULL), _size(0)
{
	std::cout << BGREEN << "Default constructor called" << RESET << std::endl;
}

template<typename T>
Array<T>::~Array()
{
	std::cout << BRED << "Destructor called" << RESET << std::endl;
	delete[] this->_array;
}

template<typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
	std::cout << BGREEN << "Parametric constructor called" << RESET << std::endl;
}

template<typename T>
size_t Array<T>::size() const
{
	return this->_size;
}

template<typename T>
const T& Array<T>::operator[](unsigned int i) const
{
	if (i >= this->_size)
		throw std::out_of_range("Index out of range");
	return this->_array[i];
}

template<typename T>
 T& Array<T>::operator[](unsigned int i)
{
	if (i >= this->_size)
		throw std::out_of_range("Index out of range");
	return this->_array[i];
}

template<typename T>
Array<T>& Array<T>::operator=(Array const &other)
{
	std::cout << BBLUE << "Copy assignment operator called" << RESET << std::endl;
	Array<T> tmp(other);

	T *savedArray = this->_array;
	size_t savedSize = this->_size;

	this->_array = tmp._array;
	this->_size = tmp._size;
	tmp._array = savedArray;
	tmp._size = savedSize;
	return *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr)
{
	for (unsigned int i = 0; i < arr.size(); i++)
		os << arr[i] << " ";
	return os;
}

template<typename T>
Array<T>::Array(Array const &original) : _array(new T[original._size]), _size(original._size)
{
	std::cout << BBLUE << "Copy constructor called" << RESET << std::endl;
	try
	{
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = original._array[i];
	}
	catch (...)
	{
		delete[] this->_array;
		throw;
	}
}

#endif //ARRAY_TPP
