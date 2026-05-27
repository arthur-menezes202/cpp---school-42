/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 05:21:34 by armeneze          #+#    #+#             */
/*   Updated: 2026/05/05 21:42:11 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	private:
		Brain *_brain;
	public:
		Cat();
		~Cat();
		Cat(Cat const &other);
		Cat & operator=(Cat const &other);
		void makeSound() const override;
		
};

#endif