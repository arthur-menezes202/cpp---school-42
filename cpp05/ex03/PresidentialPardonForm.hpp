#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP


#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &other);
		PresidentialPardonForm & operator=(PresidentialPardonForm const &other);
		PresidentialPardonForm(std::string target);
		void execute(Bureaucrat const & executor) const;
};

#endif