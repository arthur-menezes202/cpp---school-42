/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:32:31 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/21 16:14:48 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

PhoneBook::PhoneBook() : _index(0) {}
PhoneBook::~PhoneBook() {}

std::string PhoneBook::validation_input_string(std::string prompt)
{
	std::string input;
	
	while (true) {
		std::cout << prompt;
		if (!std::getline(std::cin, input)) {
			std::cout << "\nEOF detected. Exiting..." << std::endl;
			exit(0); 
		}
		if (!input.empty()) {
			size_t first = input.find_first_not_of(" \t\n\r");
			if (first != std::string::npos)
				return input;
		}
		std::cout << "Invalid input. Please try again." << std::endl;
	}
}

int PhoneBook::validation_input_number(int number)
{
	return 1;
}

void PhoneBook::add_phone_book()
{
	std::string input;
	Contact     new_contact;
	PhoneBook pb;

	input = pb.validation_input_string("Write Name: ");
	new_contact.set_name(input);

	input = pb.validation_input_string("Write Last Name: ");
	new_contact.set_last_name(input);

	input = pb.validation_input_string("Write Surname: ");
	new_contact.set_nick_name(input);

	input = pb.validation_input_string("Write Phone Number: ");
	new_contact.set_phone_number(input);

	input = pb.validation_input_string("Write Phone Number: ");
	new_contact.set_secret(input);

	this->_contacts[this->_index % 8] = new_contact;
	this->_index++;
}
std::string format_string(std::string str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}
void PhoneBook::search_contact()
{
	int limit;
	std::string input;
    if (this->_index > 8)
        limit = 8;
    else
        limit = this->_index;

	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|      Name| Last Name|   Surname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;

    for (int i = 0; i < limit; i++) {
		std::cout << "|" << std::setw(10) << i + 1;
        std::cout << "|" << std::setw(10) << format_string(_contacts[i].get_name());
        std::cout << "|" << std::setw(10) << format_string(_contacts[i].get_last_name());
        std::cout << "|" << std::setw(10) << format_string(_contacts[i].get_nick_name());
        std::cout << "|" << std::endl;
    }
	std::cout << "|-------------------------------------------|" << std::endl;
	
	std::cout << "please, insert the index for more informations: ";
	std::getline(std::cin, input);
	

}
