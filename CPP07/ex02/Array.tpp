/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-11 19:18:31 by rmunoz-c          #+#    #+#             */
/*   Updated: 2026-03-11 19:18:31 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

/* ========================================================================== */
/*                          DEFAULT CONSTRUCTOR                               */
/* ========================================================================== */

template <typename T>
Array<T>::Array() : _data(NULL), _size(0)
{
}

/* ========================================================================== */
/*                       CONSTRUCTOR WITH SIZE                                */
/* ========================================================================== */

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n)
{
}

/* ========================================================================== */
/*                          COPY CONSTRUCTOR                                  */
/* ========================================================================== */

template <typename T>
Array<T>::Array(const Array &other) : _data(NULL), _size(0)
{
	*this = other;
}

/* ========================================================================== */
/*                       ASSIGNMENT OPERATOR                                  */
/* ========================================================================== */

template <typename T>
Array<T>& Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] _data;
		_size = other._size;
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
	return (*this);
}

/* ========================================================================== */
/*                               DESTRUCTOR                                   */
/* ========================================================================== */

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

/* ========================================================================== */
/*                      SUBSCRIPT OPERATOR (NON-CONST)                        */
/* ========================================================================== */

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return (_data[index]);
}

/* ========================================================================== */
/*                       SUBSCRIPT OPERATOR (CONST)                           */
/* ========================================================================== */

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return (_data[index]);
}

/* ========================================================================== */
/*                               SIZE FUNCTION                                */
/* ========================================================================== */

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

#endif