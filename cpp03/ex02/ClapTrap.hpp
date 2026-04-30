/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:16:16 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/29 20:17:09 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <stdint.h>
#include <cmath>

class ClapTrap
{
	protected:
		std::string  _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
	public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap(std::string target);
		ClapTrap & operator=(ClapTrap const &other);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		bool hasHitPoints();
		void removeEnergyPoints();
		void setName(std::string name);
		std::string getName();


};

#endif