/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 01:16:01 by armeneze          #+#    #+#             */
/*   Updated: 2026/05/08 02:44:56 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form{
	private:
		std::string _nameForm;
		bool _signed;
		const int _gradeSigned;
		const int _gradeExec;
	public:
		Form();
		~Form();
		Form(Form const &other);
		Form & operator=(Form const &other);
		Form(std::string name, int gradeSigned, int gradExec);
		void print(std::ostream& os) const;
		std::string getName() const;
		std::string getNameForm();
		bool getSigned() const;
		int getGradeSigned() const;
		int getGradeExec() const;
		void beSigned(Bureaucrat &b);
		
	};
std::ostream& operator<<(std::ostream& os, const Form& b);
#endif