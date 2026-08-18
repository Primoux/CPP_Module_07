/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 16:48:24 by enchevri          #+#    #+#             */
/*   Updated: 2026/08/18 11:58:01 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
	if (this->_size > 0)
	{
		// for (unsigned int i = 0; i < this->_size; i++)
		// 	delete this->_array[i];
		delete[] this->_array;
	}
}

template<typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
	std::cout << BGREEN << "Parametric constructor called" << RESET << std::endl;
}

#endif //ARRAY_TPP