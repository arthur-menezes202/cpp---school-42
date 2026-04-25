/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:53:52 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/24 18:10:59 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) {
	this->name = name;
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon* obj){
	this->weaponPtr = obj;
}

void HumanB::attack() {
	std::cout << this->name;
	std::cout << " attacks with their ";
	std::cout << this->weaponPtr->getType();
	std::cout << std::endl;
}