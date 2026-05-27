/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 01:54:28 by armeneze          #+#    #+#             */
/*   Updated: 2026/05/04 18:38:54 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		~WrongAnimal();
		WrongAnimal(WrongAnimal const &other);
		WrongAnimal & operator=(WrongAnimal const &other);
		void makeSound() const;

		std::string getType() const;
};

#endif