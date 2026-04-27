/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:32:56 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/27 14:21:01 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon on my 7XL-double-cheese-triple-pickle-ketchup-special burger. I really love it!" << std::endl;
	std::cout << std::endl;
}
void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I can't believe adding extra bacon costs more money. You didn't put enough bacon on my burger! If you had, I wouldn't be asking for more.!" << std::endl;
	std::cout << std::endl;
}
void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve extra bacon for free.";
	std::cout <<  "I've been coming here for years, while you only started working here last month.." << std::endl;
	std::cout << std::endl;
}
void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void Harl::complain( std::string level )
{
	typedef void (Harl::*HarlMemFn)();
	std::string names[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	HarlMemFn functions[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	int i = 0;
	while (i < 4) {
		if (names[i] == level) {
			break;
		}
		i ++;
	}
	switch (i) {
	case 0:
		(this->*functions[i])();
		i ++;
	case 1:
		(this->*functions[i])();
		i ++;
	case 2:
		(this->*functions[i])();
		i ++;
	case 3:
		(this->*functions[i])();
		i ++;
		break;
	default:
		std::cout << "Probably complaining about insignificant problems." << std::endl;
	}
	return ;
}