#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP


#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &other);
		RobotomyRequestForm & operator=(RobotomyRequestForm const &other);
		RobotomyRequestForm(std::string target);
		void execute(Bureaucrat const & executor) const;
};

#endif