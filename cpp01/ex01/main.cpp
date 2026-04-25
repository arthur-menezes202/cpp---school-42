/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:25:04 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/22 17:12:50 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main()
{

	int n = 10;
	Zombie* netan;
	netan = zombieHorde( n, "Netan" );
	for(int i = 0;i < n; i++)
	{
		netan[i].announce();
	}
	delete[] netan;
}