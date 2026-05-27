#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
Intern::Intern()
{

}

Intern::~Intern()
{}

Intern::Intern(Intern const &other)
{
	if (this != &other)
	{
		(void)other;
	}
}

Intern & Intern::operator=(Intern const &other)
{
	if (this != &other)
	{
		(void)other;
	}
	return *this;
}

AForm*  Intern::makeForm(std::string nameForm, std::string target)
{
	std::string forms[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
	int result = 0;
	
    for(int i = 0; i < 3; i++)
	{
		if(forms[i] == nameForm)
		{
			std::cout << "Intern create " << target << std::endl;
			break;
		}
		result ++;
	}
	std::cout << result << std::endl;
	switch (result) {
		case 0:
			return new ShrubberyCreationForm(target);
			break;
		case 1: 
			return new RobotomyRequestForm(target);
			break;
		case 2: 
			return new PresidentialPardonForm(target);
			break;
		default:
			break;
	}
	std::cout << "Error: Intern cannot create " << nameForm << " (Form name unknown)" << std::endl;
	return NULL;
}
