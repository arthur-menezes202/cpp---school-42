#include "AForm.hpp"
#include "Bureaucrat.hpp"

static bool validation_grade_form_constructor(int grade)
{
	if (grade < 1)
	{
		throw std::out_of_range("AForm::GradeTooHighException");
	}
	if (grade > 150)
	{
		throw std::out_of_range("AForm::GradeTooLowException");
	}
	return true;
}

AForm::AForm() : _gradeSigned(150), _gradeExec(150)
{
	this->_nameForm = "default";
	this->_signed = false;
}

AForm::~AForm() {}

AForm::AForm(AForm const &other) : _gradeSigned(other._gradeSigned), _gradeExec(other._gradeExec)
{
	validation_grade_form_constructor(this->_gradeSigned);
	validation_grade_form_constructor(this->_gradeExec);
	*this = other;
}

AForm & AForm::operator=(AForm const &other)
{
	if (this != &other)
	{
		(void)other;
	}
	return *this;
}

void AForm::print(std::ostream& os) const
{
	os << "AForm [" << _nameForm << "]: "
		<< "Status: " << (_signed ? "Signed" : "Not signed")
		<< " | Required Grade to Sign: " << _gradeSigned
		<< " | Required Grade to Exec: " << _gradeExec;
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	f.print(os);
	return os;
}

AForm::AForm(std::string name, int gradeSigned, int gradExec) :
_gradeSigned(gradeSigned), _gradeExec(gradExec)
{
	validation_grade_form_constructor(this->_gradeSigned);
	validation_grade_form_constructor(this->_gradeExec);
	this->_nameForm = name;
	this->_signed = false;
}

std::string AForm::getNameForm() const
{
	return this->_nameForm;
}

bool AForm::getSigned() const
{
	return this->_signed;
}

int AForm::getGradeSigned() const
{
	return this->_gradeSigned;
}

int AForm::getGradeExec() const
{
	return this->_gradeExec;
}

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->_gradeSigned)
	{
		if(this->_signed == true)
		{
			throw std::out_of_range("AForm::this form signed");
		}
		this->_signed = true;
	}
	else
	{
		throw std::out_of_range("AForm::GradeTooLowException");
	}
}

std::string AForm::FormNotSignedException()
{
	return ("AForm::FormNotSignedException");
}
std::string AForm::GradeTooLowException()
{
	return ("AForm::GradeTooLowException");
}