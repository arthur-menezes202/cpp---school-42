/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 23:33:57 by armeneze          #+#    #+#             */
/*   Updated: 2026/05/08 00:28:05 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class AForm;

class Bureaucrat 
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat(std::string name, int grade);
		Bureaucrat & operator=(Bureaucrat const &other);
		void print(std::ostream& os) const;
		std::string getName();
		int getGrade() const;
		void upGrade();
		void dowGrade();
		void signForm(AForm &form);
		void executeForm(AForm const & form);

};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
bool validation_grade(int grade);
bool validation_grade_bureaucrat(int grade);

#endif