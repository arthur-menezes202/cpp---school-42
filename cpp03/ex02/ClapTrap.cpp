/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:23:36 by armeneze          #+#    #+#             */
/*   Updated: 2026/05/01 19:34:48 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->_name = "<don't have name>";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap " << this->_name << " boot sequence completed. Hello, traveler!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " die" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
}

ClapTrap::ClapTrap(std::string target)
{
	this->_name = target;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap " << this->_name << " boot sequence completed. Hello, traveler!" << std::endl;

}
ClapTrap &ClapTrap::operator=(ClapTrap const &other)

{
	if (this != &other)
	{
		(void)other;
		return *this;
	}
	return *this;
}

bool ClapTrap::hasHitPoints()
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " can't attack! No energy or HP left." << std::endl;
		return false;
	}
	return true;
}

void ClapTrap::removeEnergyPoints()
{
	this->_energyPoints--;
}

void ClapTrap::attack(const std::string& target) {
	if(!this->hasHitPoints())
		return;
	this->removeEnergyPoints();
	std::cout << "ClapTrap " << this->_name << " attacks " << target << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if(!this->hasHitPoints())
		return;
	this->removeEnergyPoints();
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " take damage " << amount
		<< ", have " << this->_hitPoints << " Hit Points" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if(!this->hasHitPoints())
		return;
	this->_hitPoints += amount;
	this->removeEnergyPoints();
	std::cout << "ClapTrap " << this->_name << " Be Repaired " << amount
		<< ", have " << this->_hitPoints << " Hit Points" << std::endl;
}

void ClapTrap::setName(std::string name)
{
	this->_name = name;
}

std::string ClapTrap::getName()
{
	return this->_name;
}