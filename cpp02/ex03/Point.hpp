/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 20:19:50 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/29 15:47:29 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"
class Point {
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point();
		Point(float const n1, float const n2);
		Point(const Point &other);
		Point &operator=(Point const &other);
		~Point();

		Fixed getX() const;
		Fixed getY() const;

};
bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif