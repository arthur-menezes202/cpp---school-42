/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:00:27 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/29 16:05:36 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->numberFixed = 0;
}

Fixed::Fixed(const int n)
{
	int32_t fixed_point_value = n << _fractional_bits;
	this->numberFixed = fixed_point_value;
}

Fixed::Fixed(const float n)
{
	int32_t fixed_point_value = roundf(n * (1 << _fractional_bits));
	this->numberFixed = fixed_point_value;
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		this->numberFixed = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {}

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

bool Fixed::operator>(const Fixed &obj) const {return (long)this->getRawBits() > (long)obj.getRawBits();}
bool Fixed::operator<(const Fixed &obj) const {return (long)this->getRawBits() < (long)obj.getRawBits();}
bool Fixed::operator>=(const Fixed &obj) const {return (long)this->getRawBits() >= (long)obj.getRawBits();}
bool Fixed::operator<=(const Fixed &obj) const {return (long)this->getRawBits() <= (long)obj.getRawBits();}
bool Fixed::operator==(const Fixed &obj) const {return (long)this->getRawBits() == (long)obj.getRawBits();}
bool Fixed::operator!=(const Fixed &obj) const {return (long)this->getRawBits() != (long)obj.getRawBits();}

Fixed Fixed::operator+(const Fixed &obj) const {return Fixed(this->toFloat() + obj.toFloat());}
Fixed Fixed::operator-(const Fixed &obj) const {return Fixed(this->toFloat() - obj.toFloat());}
Fixed Fixed::operator*(const Fixed &obj) const {return Fixed(this->toFloat() * obj.toFloat());}
Fixed Fixed::operator/(const Fixed &obj) const {return Fixed(this->toFloat() / obj.toFloat());}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	++(this->numberFixed);
	return (tmp);
}
Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	--(this->numberFixed);
	return (tmp);
}
Fixed& Fixed::operator++()
{
	this->numberFixed++;
    return *this;
}

Fixed& Fixed::operator--()
{
	this->numberFixed--;
    return *this;
}

Fixed& Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
	if(obj1.getRawBits() < obj2.getRawBits())
		return (Fixed &)obj1;
	return (Fixed &)obj2;
}

Fixed& Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
	if(obj1.getRawBits() > obj2.getRawBits())
		return (Fixed &)obj1;
	return (Fixed &)obj2;
}

Fixed& Fixed::min(Fixed &obj1, Fixed &obj2)
{
	if(obj1.getRawBits() < obj2.getRawBits())
		return (Fixed &)obj1;
	return (Fixed &)obj2;
}

Fixed& Fixed::max(Fixed &obj1, Fixed &obj2)
{
	if(obj1.getRawBits() > obj2.getRawBits())
		return (Fixed &)obj1;
	return (Fixed &)obj2;
}

