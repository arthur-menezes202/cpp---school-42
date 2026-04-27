/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:30:57 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/27 13:37:25 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>

class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public:
	Harl();
	~Harl();
	void complain( std::string level );
};

#endif