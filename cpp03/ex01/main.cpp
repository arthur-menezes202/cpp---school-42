/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:54:33 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/29 21:20:41 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main() {
    std::cout << "===== TEST 1: CONSTRUCTION AND ATTRIBUTES =====" << std::endl;
    {
        ClapTrap clappy("Clap-1");
        ScavTrap scavvy("Scav-2");

        std::cout << "\n--- Status Initials ---" << std::endl;
        clappy.attack("a target");
        scavvy.attack("the same target");
    }

    std::cout << "\n\n===== TEST 2: MODO GUARD GATE =====" << std::endl;
    {
        ScavTrap robot("GateKeeper");

        robot.attack("Intruso");
        robot.takeDamage(30);
        robot.beRepaired(10);

        robot.guardGate();
    }

    std::cout << "\n\n===== TEST 3: COPY AND ATTRIBUTION =====" << std::endl;
    {
        ScavTrap original("Original");
        original.guardGate();

        ScavTrap copia(original);
        std::cout << "Copy name: " << copia.getName() << std::endl;

        ScavTrap outro("Other");
        outro = original;
    }

    return 0;
}