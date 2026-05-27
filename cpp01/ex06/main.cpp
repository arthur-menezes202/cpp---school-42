/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:30:49 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/27 14:08:22 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if(ac != 2)
	{
		std::cout << "Arguments invalids." << std::endl;
		return (0);
	}
	Harl harl;
	std::string arg;
	
	arg = av[1];
	harl.complain(arg);
	return (0);
}