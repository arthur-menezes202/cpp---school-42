/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 16:25:26 by armeneze          #+#    #+#             */
/*   Updated: 2026/05/01 18:13:44 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :  ClapTrap("_clap_name"), ScavTrap(), FragTrap()
{
    this->_name = "";
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap " << this->_name << " constructed!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : 
    ClapTrap(name + "_clap_name"), 
    ScavTrap(name), 
    FragTrap(name)
{
    this->_name = name; // Atributo da DiamondTrap
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    
    std::cout << "DiamondTrap constructed!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->_name << " desconstructed!" << std::endl;
}

DiamondTrap:: DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	this->_name = other._name;
	std::cout << "DiamondTrap copy constructor called for " << this->_name << std::endl;
}


DiamondTrap & DiamondTrap::operator=(DiamondTrap const &other) 
{
	if (this != &other)
	{
		(void)other;
		return *this;
	}
	return *this;
}

void DiamondTrap::whoAmI() {
    std::cout << "who Am I? DiamondName: " << this->_name 
              << " | ClapTrapName: " << ClapTrap::_name << std::endl;
}
