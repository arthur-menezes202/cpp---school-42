/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:29:11 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/29 21:24:51 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "FragTrap " << this->_name << " constructed!" << std::endl;
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->_name << " desconstructed!" << std::endl;
}
FragTrap & FragTrap::operator=(FragTrap const &other)
{
	if (this != &other)
	{
		(void)other;
		return *this;
	}
	return *this;
}
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called for " << _name << std::endl;
}

void FragTrap::guardGate()
{
	std::cout << "FragTrap " << _name << " is Gate keeper mode" << std::endl;
}