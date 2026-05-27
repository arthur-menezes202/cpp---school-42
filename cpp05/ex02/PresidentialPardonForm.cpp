#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default_shrubbery", 25, 5)
{
	_target = "defaut";
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) :
AForm(other._target, other.getGradeSigned(), other.getGradeExec())
{
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{
	_target = target;
}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false) {
		throw std::out_of_range(AForm::FormNotSignedException());
	}
	if (executor.getGrade() > this->getGradeExec()) {
		throw std::out_of_range(AForm::GradeTooLowException());
    }
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	
}