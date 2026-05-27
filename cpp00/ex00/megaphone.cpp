/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:32:48 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/22 16:37:37 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype.h>
#include <string>

int main(int ac, char **av) {
	int x;
	int empty = 0;
	
	for (int y = 1; y < ac; y ++)
	{
		x = 0;
		if(av[y][0] == '\0')
		{
			continue;
		}
		empty = 1;
		while (av[y][x] != '\0') {
			std::cout << (char) toupper(av[y][x]);
			x ++;
		}
	}
	if(empty == 0 || ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	std::cout << "\n";
	return 0;
}