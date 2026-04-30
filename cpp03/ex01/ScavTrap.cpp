/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:29:11 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/29 20:13:56 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " << this->_name << " constructed!" << std::endl;
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->_name << " desconstructed!" << std::endl;
}
ScavTrap & ScavTrap::operator=(ScavTrap const &other)
{
	if (this != &other)
	{
		(void)other;
		return *this;
	}
	return *this;
}
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called for " << _name << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is Gate keeper mode" << std::endl;
}