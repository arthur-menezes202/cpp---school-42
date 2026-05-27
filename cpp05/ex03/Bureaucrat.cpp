/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 23:40:07 by armeneze          #+#    #+#             */
/*   Updated: 2026/05/08 00:28:15 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): _name("defaut")
{
	this->_grade = 150;
}
Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
{
	*this = other;
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	validation_grade(grade);
	this->_grade = grade;
}
Bureaucrat & Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

void Bureaucrat::print(std::ostream& os) const
{
	os << this->_name << ", Bureaucrat with grade " << this->_grade << ".";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	b.print(os);
	return os;
}

std::string Bureaucrat::getName()
{
	return this->_name;
}
int Bureaucrat::getGrade() const
{
	return this->_grade;
}
void Bureaucrat::upGrade()
{
	validation_grade_bureaucrat(this->_grade);
	this->_grade--;
}
void Bureaucrat::dowGrade()
{
	validation_grade_bureaucrat(this->_grade);
	this->_grade++;
}

void Bureaucrat::signForm(AForm &form)
{
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getNameForm() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << this->_name << " couldn't sign " << form.getNameForm() 
				<< " because " << e.what() << std::endl;
	}
}

bool validation_grade(int grade)
{
	if(grade < 1)
	{
		throw std::out_of_range("Bureaucrat::GradeTooHighException");
		return false;
	}
	if(grade > 150)
	{
		throw std::out_of_range("Bureaucrat::GradeTooLowException");
		return false;
	}
	return true;
}


bool validation_grade_bureaucrat(int grade)
{
	int newGrade = grade - 1;
	if(newGrade < 1)
	{
		throw std::out_of_range("Bureaucrat::GradeTooHighException");
		return false;
	}
	newGrade = grade + 2;
	if(newGrade > 150)
	{
		throw std::out_of_range("Bureaucrat::GradeTooLowException");
		return false;
	}
	return true;
}

void Bureaucrat::executeForm(AForm const & form)
{
	try {
		form.execute(*this);
		std::cout << this->_name << " execute " << form.getNameForm() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << this->_name << " couldn't execute " << form.getNameForm() 
				<< " because " << e.what() << std::endl;
	}
}
