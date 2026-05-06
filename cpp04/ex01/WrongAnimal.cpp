/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 01:59:39 by armeneze          #+#    #+#             */
/*   Updated: 2026/05/04 18:43:52 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "<default WrongAnimal>";
	std::cout << "WrongAnimal : constructor default" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
	std::cout << "WrongAnimal : constructor whith string" << std::endl;
}
WrongAnimal::~WrongAnimal() 
{
	std::cout << "WrongAnimal : desconstructor: " << this->type << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other)
{
	*this = other;
	std::cout << "WrongAnimal : constructor copy" << std::endl;
}
	
WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
	if (this != &other)
	{
		(void)other;
		return *this;
	}
	std::cout << "WrongAnimal : operator =" << std::endl;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "this animal " << this->type << " Make a Sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}
