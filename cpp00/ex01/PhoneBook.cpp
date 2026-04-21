/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:32:31 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/21 17:33:32 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _index(0) {}
PhoneBook::~PhoneBook() {}

std::string PhoneBook::validation_input_string(std::string prompt)
{
	std::string input;
	
	while (true) {
		std::cout << prompt;
		getline (std::cin, input);
		if (std::cin.eof())
		{
			std::cin.clear();
			clearerr(stdin);
			std::cout << std::endl;
			continue;
		}
		if (!input.empty()) {
			size_t first = input.find_first_not_of(" \t\n\r");
			if (first != std::string::npos)
				return input;
		}
		std::cout << "Invalid input. Please try again." << std::endl;
	}
}

bool is_valid_phone(std::string str) {
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.length(); i++) {
        // Permite apenas dígitos (você pode adicionar ' ' ou '-' se quiser)
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

std::string PhoneBook::validation_input_number(std::string prompt)
{
		std::string input;
	
	while (true) {
		std::cout << prompt;
		getline (std::cin, input);
		if (std::cin.eof())
		{
			std::cin.clear();
			clearerr(stdin);
			std::cout << std::endl;
			continue;
		}
		if (is_valid_phone(input)) {
			return input;
		}
		std::cout << "Invalid input. Please try again." << std::endl;
	}
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

	input = pb.validation_input_number("Write Phone Number: ");
	new_contact.set_phone_number(input);

	input = pb.validation_input_string("Write a secret: ");
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
	PhoneBook pb;
	
	if (this->_index > 8)
		limit = 8;
	else
		limit = this->_index;

	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|      Name| Last Name|   Surname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;

	for (int i = 0; i < limit; i++) {
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << format_string(_contacts[i].get_name());
		std::cout << "|" << std::setw(10) << format_string(_contacts[i].get_last_name());
		std::cout << "|" << std::setw(10) << format_string(_contacts[i].get_nick_name());
		std::cout << "|" << std::endl;
	}
	std::cout << "|-------------------------------------------|" << std::endl;
	
	int all;

    if (this->_index > 8)
	{
        all = 8;
	}
    else
	{
        all = this->_index;
	}
	while(42)
	{
		input = pb.validation_input_number("please, insert the index for more informations: ");
		int index = std::atoi(input.c_str());
		if(index >= 0 && index <= all - 1)
		{
			std::cout << "Name: " << _contacts[index].get_name() << std::endl;
			std::cout << "Last Name: " << _contacts[index].get_last_name() << std::endl;
			std::cout << "Surname: " << _contacts[index].get_nick_name() << std::endl;
			std::cout << "Number: " << _contacts[index].get_phone_number() << std::endl;
			std::cout << "Secret: " << _contacts[index].get_secret() << std::endl;
			break;
		}
		std::cout << "try again. " << std::endl;
	}
}
