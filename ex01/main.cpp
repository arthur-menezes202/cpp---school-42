/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:32:38 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/21 15:27:18 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

int main(int ac, char **av) {

	std::string input;
	PhoneBook PhoneBook;
	std::cout << "welcome to your phone book." << std::endl;
	while (input != "EXIT")
	{
		std::cout << "commands:" << std::endl;
		std::cout << "ADD    | Add new contact" << std::endl;
		std::cout << "SEARCH | search existing contact" << std::endl;
		std::cout << "EXIT   | close phone book" << std::endl;
		getline (std::cin, input);
		if(input == "ADD")
		{
			PhoneBook.add_phone_book();
		} else if(input == "SEARCH")
		{
			PhoneBook.search_contact();
		} else {
			std::cout << "command not found: please try again" << std::endl;
		}
	}
}
