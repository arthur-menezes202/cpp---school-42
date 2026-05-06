/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 18:56:43 by armeneze          #+#    #+#             */
/*   Updated: 2026/05/05 21:31:24 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
	protected:
		std::string ideas[100];
	public:
		Brain();
		~Brain();
		Brain & operator=(Brain const &other);
		Brain(Brain const &other);
		void setIdea(int pos, std::string idea);


};

#endif