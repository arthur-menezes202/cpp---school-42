#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP


#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &other);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const &other);
		ShrubberyCreationForm(std::string target);
		void execute(Bureaucrat const & executor) const;
		void createFile() const;
};

#endif