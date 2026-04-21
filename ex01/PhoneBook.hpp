/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:32:29 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/21 17:20:36 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "main.hpp"
# include "Contact.hpp"
class PhoneBook {
	private:
		Contact _contacts[8];
		int _index;
	public:
		PhoneBook();
		~PhoneBook();
		
		std::string validation_input_string(std::string prompt);
		std::string validation_input_number(std::string prompt);
		void add_phone_book();
		void search_contact();

};

void addPhoneBook();
#endif