/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 01:35:10 by armeneze          #+#    #+#             */
/*   Updated: 2026/05/06 02:59:40 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

static bool validation_grade_form_constructor(int grade)
{
	if (grade < 1)
	{
		throw std::out_of_range("Form::GradeTooHighException");
	}
	if (grade > 150)
	{
		throw std::out_of_range("Form::GradeTooLowException");
	}
	return true;
}

Form::Form() : _gradeSigned(150), _gradeExec(150)
{
	this->_nameForm = "default";
	this->_signed = false;
}

Form::~Form() {}

Form::Form(Form const &other) : _gradeSigned(other._gradeSigned), _gradeExec(other._gradeExec)
{
	validation_grade_form_constructor(this->_gradeSigned);
	validation_grade_form_constructor(this->_gradeExec);
	*this = other;
}

Form & Form::operator=(Form const &other)
{
	if (this != &other)
	{
		(void)other;
	}
	return *this;
}

void Form::print(std::ostream& os) const
{
	os << "Form [" << _nameForm << "]: "
		<< "Status: " << (_signed ? "Signed" : "Not signed")
		<< " | Required Grade to Sign: " << _gradeSigned
		<< " | Required Grade to Exec: " << _gradeExec;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	f.print(os);
	return os;
}

Form::Form(std::string name, int gradeSigned, int gradExec) :
_gradeSigned(gradeSigned), _gradeExec(gradExec)
{
	validation_grade_form_constructor(this->_gradeSigned);
	validation_grade_form_constructor(this->_gradeExec);
	this->_nameForm = name;
	this->_signed = false;
}

std::string Form::getNameForm()
{
	return this->_nameForm;
}

bool Form::getSigned() const
{
	return this->_signed;
}

int Form::getGradeSigned() const
{
	return this->_gradeSigned;
}

int Form::getGradeExec() const
{
	return this->_gradeExec;
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->_gradeSigned)
	{
		if(this->_signed == true)
		{
			throw std::out_of_range("Form::this form signed");
		}
		this->_signed = true;
	}
	else
	{
		throw std::out_of_range("Form::GradeTooLowException");
	}
}
