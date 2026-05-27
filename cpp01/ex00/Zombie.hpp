/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:14:06 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/22 15:45:48 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

class Zombie {
	public:
		Zombie(std::string name);
		~Zombie();
		void announce( void );

	private:
		std::string name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif