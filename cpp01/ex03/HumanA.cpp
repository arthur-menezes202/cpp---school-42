/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:53:52 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/24 17:46:56 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon& obj) : weaponRef(obj) {
	this->name = name;
}

HumanA::~HumanA() {}

void HumanA::attack() {
	std::cout << this->name;
	std::cout << " attacks with their ";
	std::cout << this->weaponRef.getType();
	std::cout << std::endl;
}