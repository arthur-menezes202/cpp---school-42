/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:14:02 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/28 19:43:14 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <stdint.h>
#include <cmath>
class Fixed
{
	private:
		int numberFixed;
		static const int _fractional_bits = 8;

	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed &other);

		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		Fixed& operator=(const Fixed &other);
		
		bool operator>(const Fixed &obj) const;
		bool operator<(const Fixed &obj) const;
		bool operator>=(const Fixed &obj) const;
		bool operator<=(const Fixed &obj) const;
		bool operator==(const Fixed &obj) const;
		bool operator!=(const Fixed &obj) const;
				
		Fixed operator+(const Fixed &obj) const;
		Fixed operator*(const Fixed &obj) const;
		Fixed operator-(const Fixed &obj) const;
		Fixed operator/(const Fixed &obj) const;

		Fixed operator++(int);
		Fixed operator--(const int);
		Fixed& operator++();
		Fixed& operator--();

		static Fixed& min(const Fixed &obj1, const Fixed &obj2);
		static Fixed& max(const Fixed &obj1, const Fixed &obj2);
		static Fixed& min(Fixed &obj1, Fixed &obj2);
		static Fixed& max(Fixed &obj1, Fixed &obj2);
};
std::ostream & operator<<(std::ostream & out, const Fixed & obj);
#endif