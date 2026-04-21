/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:32:36 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/21 15:12:54 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include "main.hpp"

class Contact {
	private:
		std::string _name;
		std::string _last_name;
		std::string _nick_name;
		std::string _phone_number;
		std::string _secret;
	public: 
	Contact();
	~Contact();

	
	Contact(int id, std::string _name, std::string _last_name, std::string _nick_name, std::string _phone_number, std::string _secret);
	void set_name(std::string str);
	void set_last_name(std::string str);
	void set_nick_name(std::string str);
	void set_phone_number(std::string str);
	void set_secret(std::string str);

	std::string get_name() const;
	std::string get_last_name() const;
	std::string get_nick_name() const;
	std::string get_phone_number() const;
	std::string get_secret() const;
};
#endif