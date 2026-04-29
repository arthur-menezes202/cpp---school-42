/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:56:52 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/29 16:03:27 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

#include <iostream>
#include "Point.hpp"

void check_point(std::string name, bool is_inside) {
    std::cout << "Ponto " << name << ": "
              << (is_inside ? "\033[32mINSIDE\033[0m" : "\033[31mNOT INSIDE\033[0m")
              << std::endl;
}

int main( void ) {
    Point const a(0, 0);
    Point const b(10, 0);
    Point const c(0, 10);

    std::cout << "--- testing triangle: A(0,0), B(10,0), C(0,10) ---\n" << std::endl;

    Point const p_inside(2, 2);
    check_point("P_INDIDE (2, 2)", bsp(a, b, c, p_inside));

    Point const p_outside(15, 15);
    check_point("NOT_INSIDE (15, 15)", bsp(a, b, c, p_outside));

    Point const p_outside_edge(6, 6);
    check_point("P_OUTSIDE_NEAR (6, 6)", bsp(a, b, c, p_outside_edge));

    Point const p_edge(5, 0);
    check_point("P_ON_THE_EDGE (5, 0)", bsp(a, b, c, p_edge));

    Point const p_vertex(0, 0);
    check_point("P_NO_VERTICE (0, 0)", bsp(a, b, c, p_vertex));

    return 0;
}