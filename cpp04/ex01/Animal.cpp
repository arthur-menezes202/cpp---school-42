/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 01:59:39 by armeneze          #+#    #+#             */
/*   Updated: 2026/05/05 21:24:25 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "default";
	std::cout << "Animal : constructor default" << std::endl;
}
Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "Animal : constructor whith string" << std::endl;
}
Animal::~Animal() 
{
	std::cout << "Animal : desconstructor" << std::endl;
}

Animal::Animal(Animal const &other)
{
	*this = other;
	std::cout << "Animal : constructor copy" << std::endl;
}
	
Animal &Animal::operator=(Animal const &other)
{
	if (this != &other)
	{
		(void)other;
		return *this;
	}
	std::cout << "Animal : operator =" << std::endl;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "this animal " << this->type << " Make a Sound" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}
