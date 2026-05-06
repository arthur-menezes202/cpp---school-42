/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 05:22:45 by armeneze          #+#    #+#             */
/*   Updated: 2026/05/05 21:41:58 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat : constructor default" << std::endl;

}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat : desconstructor" << std::endl;
}

Cat::Cat(Cat const &other) : Animal(other)
{
	this->_brain = new Brain(*other._brain);
	this->type = other.type;
	std::cout << "Cat : constructor copy" << std::endl;
}

Cat & Cat::operator=(Cat const &other)
{
	std::cout << "Cat : constructor operator =" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		delete this->_brain; 
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat say mew" << std::endl;
}
