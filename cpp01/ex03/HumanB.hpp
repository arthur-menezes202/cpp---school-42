/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:38:57 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/24 18:10:50 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB 
{
	private:
		Weapon* weaponPtr;
		std::string name;
	public:
	HumanB(std::string name);
	~HumanB();

	void setWeapon(Weapon* ptr);
	void attack();
};

#endif