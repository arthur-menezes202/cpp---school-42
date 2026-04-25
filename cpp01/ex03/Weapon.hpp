/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:28:57 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/24 17:46:05 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon {
	private:
		std::string type;
	public:
		Weapon(std::string type);
		~Weapon();
		
		std::string getType() const;
		void setType(std::string type);
};

#endif