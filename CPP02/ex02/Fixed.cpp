/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-15 10:17:03 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-07-15 10:17:03 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = static_cast<int>(roundf(f * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	_fixedPointValue = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_fixedPointValue = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _fixedPointValue >> _fractionalBits;
}

bool Fixed::operator>(const Fixed &other) const
{
	return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->_fixedPointValue != other._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_fixedPointValue + other._fixedPointValue);
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_fixedPointValue - other._fixedPointValue);
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	long long mul = (long long)this->_fixedPointValue * other._fixedPointValue;
	result.setRawBits(static_cast<int>(mul >> _fractionalBits));
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	long long dividend = ((long long)this->_fixedPointValue << _fractionalBits);
	result.setRawBits(static_cast<int>(dividend / other._fixedPointValue));
	return (result);
}

Fixed &Fixed::operator++()
{
    _fixedPointValue += (1 << _fractionalBits);
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    _fixedPointValue += (1 << _fractionalBits);
    return (temp);
}

Fixed &Fixed::operator--()
{
    _fixedPointValue -= (1 << _fractionalBits);
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    _fixedPointValue -= (1 << _fractionalBits);
    return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
