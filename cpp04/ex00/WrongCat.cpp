/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 05:22:45 by armeneze          #+#    #+#             */
/*   Updated: 2026/05/05 21:17:52 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat : constructor default" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat : desconstructor" << std::endl;
}

WrongCat::WrongCat(WrongCat const &other) : WrongAnimal(other)
{
    this->type = other.type;
	std::cout << "WrongCat : constructor copy" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const &other)
{
	if (this != &other)
	{
		(void)other;
		return *this;
	}
	std::cout << "WrongCat : constructor operator =" << std::endl;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat say mew" << std::endl;
}
