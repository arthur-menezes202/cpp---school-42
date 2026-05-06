/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 05:22:45 by armeneze          #+#    #+#             */
/*   Updated: 2026/05/05 21:17:43 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog : constructor default" << std::endl;

}

Dog::~Dog()
{
	std::cout << "Dog : desconstructor" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other)
{
    this->type = other.type;
	std::cout << "Dog : constructor copy" << std::endl;
}

Dog & Dog::operator=(Dog const &other)
{
	if (this != &other)
	{
		(void)other;
		return *this;
	}
	std::cout << "Dog : constructor operator =" << std::endl;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog say au au" << std::endl;
}
