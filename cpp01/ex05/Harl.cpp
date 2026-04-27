/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:32:56 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/27 13:53:45 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void Harl::debug( void )
{
	std::cout << "I love having extra bacon on my 7XL-double-cheese-triple-pickle-ketchup-special burger. I really love it!" << std::endl;
}
void Harl::info( void )
{
	std::cout << "I can't believe adding extra bacon costs more money. You didn't put enough bacon on my burger! If you had, I wouldn't be asking for more.!" << std::endl;
}
void Harl::warning( void )
{
	std::cout << "I think I deserve extra bacon for free. I've been coming here for years, while you only started working here last month.." << std::endl;
}
void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	typedef void (Harl::*HarlMemFn)();
	std::string names[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	HarlMemFn functions[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	for (int i = 0; i < 4; i++) {
		if (names[i] == level) {
			(this->*functions[i])();
			return;
		}
	}

	std::cout << "Error: Level '" << level << "' don't exist." << std::endl;
}