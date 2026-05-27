/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 05:22:45 by armeneze          #+#    #+#             */
/*   Updated: 2026/05/05 21:19:26 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog : constructor default" << std::endl;

}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog : desconstructor" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other)
{
	this->_brain = new Brain(*other._brain);
	this->type = other.type;
	std::cout << "Dog : constructor copy" << std::endl;
}

Dog & Dog::operator=(Dog const &other)
{
	std::cout << "Dog : constructor operator =" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		delete this->_brain; 
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog say mew" << std::endl;
}
