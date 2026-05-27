/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:32:40 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/21 17:28:10 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void Contact::set_name(std::string str) { this->_name = str;}

void Contact::set_last_name(std::string str) { this->_last_name = str;}

void Contact::set_nick_name(std::string str) { this->_nick_name = str;}

void Contact::set_phone_number(std::string str) { this->_phone_number = str;}

void Contact::set_secret(std::string str) { this->_secret = str;}

std::string Contact::get_name() const { return (this->_name);}

std::string Contact::get_last_name() const { return (this->_last_name);}

std::string Contact::get_nick_name() const { return (this->_nick_name);}

std::string Contact::get_phone_number() const { return (this->_phone_number);}

std::string Contact::get_secret() const { return (this->_secret);}
