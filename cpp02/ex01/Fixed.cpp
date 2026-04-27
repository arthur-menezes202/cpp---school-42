/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:00:27 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/27 18:46:49 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->numberFixed = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	int32_t fixed_point_value = n << _fractional_bits;
	this->numberFixed = fixed_point_value;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n)
{
	int32_t fixed_point_value = roundf(n * (1 << _fractional_bits));
	this->numberFixed = fixed_point_value;
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->numberFixed = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	return this->numberFixed;
}

void Fixed::setRawBits( int const raw )
{
	this->numberFixed = raw;
}

std::ostream & operator<<(std::ostream & out, const Fixed & obj) {
    float displayValue = obj.toFloat(); 
    out << displayValue;
    return out;
}

float Fixed::toFloat( void ) const
{
	float result = (float)this->numberFixed / (1 << _fractional_bits);
	return result;
}

int Fixed::toInt( void ) const
{
	int result = (this->numberFixed>>_fractional_bits);
	return result;
}