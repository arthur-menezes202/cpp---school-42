/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 20:29:10 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/29 16:29:17 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float const n1, float const n2) : x(n1), y(n2) {}

Point::Point(Point const &other) : x(other.x), y(other.y) {}

Point &Point::operator=(Point const &other)
{
	if (this != &other)
	{
		(void)other;
		return *this;
	}
	return *this;
}

Point::~Point() {}

Fixed Point::getX() const
{
	return this->x;
}

Fixed Point::getY() const
{
	return this->y;
}

