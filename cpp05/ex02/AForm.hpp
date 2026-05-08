/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 01:16:01 by armeneze          #+#    #+#             */
/*   Updated: 2026/05/08 02:51:21 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm{
	private:
		std::string _nameForm;
		bool _signed;
		const int _gradeSigned;
		const int _gradeExec;
	public:
		AForm();
		virtual ~AForm();
		AForm(AForm const &other);
		AForm & operator=(AForm const &other);
		AForm(std::string name, int gradeSigned, int gradExec);
		void print(std::ostream& os) const;
		std::string getName() const;
		std::string getNameForm() const;
		bool getSigned() const;
		int getGradeSigned() const;
		int getGradeExec() const;
		void beSigned(Bureaucrat &b);
		virtual void execute(Bureaucrat const & executor) const = 0;
		static std::string FormNotSignedException();
		static std::string GradeTooLowException();

};

std::ostream& operator<<(std::ostream& os, const AForm& b);
#endif