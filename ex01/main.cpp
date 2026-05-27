/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:32:38 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/21 17:27:39 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <stdio.h>

int main() {

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
		if (std::cin.eof())
		{
			std::cin.clear();
			clearerr(stdin);
			continue;
		}
		if(input == "ADD")
		{
			PhoneBook.add_phone_book();
		} else if(input == "SEARCH")
		{
			PhoneBook.search_contact();
		}else if(input == "EXIT")
		{
			break;
		} else {
			std::cout << "command not found: please try again" << std::endl;
		}
	}
}
