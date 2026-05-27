/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:38:57 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/24 18:07:46 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP


#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA 
{
	private:
		Weapon& weaponRef;
		std::string name;
	public:
	HumanA(std::string name, Weapon& obj);
	~HumanA();
	void attack();
};

#endif