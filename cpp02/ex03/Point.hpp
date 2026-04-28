/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 20:19:50 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/28 20:21:55 by armeneze         ###   ########.fr       */
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
		Point(int const x, int const y);
		~Point();
};

#endif