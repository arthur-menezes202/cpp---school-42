/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 20:24:58 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/29 15:59:32 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed aX = a.getX();
	Fixed aY = a.getY();

	Fixed bX = b.getX();
	Fixed bY = b.getY();

	Fixed cX = c.getX();
	Fixed cY = c.getY();

	Fixed pX = point.getX();
	Fixed pY = point.getY();
	
	Fixed denominator((bY - cY) * (aX - cX) + (cX - bX) * (aY - cY));

	if (denominator == 0) return false;

	Fixed alpha(((bY - cY) * (pX - cX) + (cX - bX) * (pY - cY)) / denominator);
	Fixed beta(((cY - aY) * (pX - cX) + (aX - cX) * (pY - cY)) / denominator);
	Fixed gamma(Fixed(1) - alpha - beta);

	return (alpha >= 0 && beta >= 0 && gamma >= 0);
}