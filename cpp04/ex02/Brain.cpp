/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 20:47:02 by armeneze          #+#    #+#             */
/*   Updated: 2026/05/05 21:33:52 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain : constructor Default" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain : desconstructor" << std::endl;
}

Brain & Brain::operator=(Brain const &other)
{
	std::cout << "Brain : constructor operator =" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::Brain(Brain const &other)
{
	*this = other;
	std::cout << "Brain : constructor copy" << std::endl;
}

void Brain::setIdea(int pos, std::string idea)
{
	this->ideas[pos] = idea;
}
