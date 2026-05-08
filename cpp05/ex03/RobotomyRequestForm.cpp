#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default_shrubbery", 72, 45)
{
	_target = "defaut";
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) :
AForm(other._target, other.getGradeSigned(), other.getGradeExec())
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{
	_target = target;
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false) {
		throw std::out_of_range(AForm::FormNotSignedException());
	}
	if (executor.getGrade() > this->getGradeExec()) {
		throw std::out_of_range(AForm::GradeTooLowException());
    }
    std::cout << "ffffffffffffpppppppppppfffffffffpfpppppppppppff" << std::endl;
    if (std::rand() % 2 == 0) {
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "The robotomy on " << this->_target << " failed." << std::endl;
    }
}