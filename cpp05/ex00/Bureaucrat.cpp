/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 23:40:07 by armeneze          #+#    #+#             */
/*   Updated: 2026/05/08 02:43:03 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
	validation_grade_bureaucrat(grade);
	this->_grade = grade;
}
Bureaucrat & Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
	{
		(void)other;
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
int Bureaucrat::getGrade()
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