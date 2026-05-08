/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 23:33:57 by armeneze          #+#    #+#             */
/*   Updated: 2026/05/08 02:43:32 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Form;

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
		int getGrade();
		void upGrade();
		void dowGrade();
		void signForm(Form &form);

};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
bool validation_grade(int grade);
bool validation_grade_bureaucrat(int grade);

#endif