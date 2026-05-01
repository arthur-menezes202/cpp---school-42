/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:28:07 by armeneze          #+#    #+#             */
/*   Updated: 2026/05/01 18:10:40 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMINFTRAP_HPP
#define DIAMINFTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string _name;
	public:

	DiamondTrap();
	DiamondTrap(std::string name);
	~DiamondTrap();
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap & operator=(const DiamondTrap& other);
	void whoAmI();

};

#endif
