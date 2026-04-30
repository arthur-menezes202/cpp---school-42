/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:18:33 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/29 20:08:32 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:

	public:
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap & operator=(ScavTrap const &other);
		ScavTrap(const ScavTrap &other);
		void guardGate();
};


#endif