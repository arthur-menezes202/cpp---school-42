#ifndef INTERN_HPP
#define INTERN_HPP


#include "AForm.hpp"

class Intern {
	private:
		std::string _target;
	public:
		Intern();
		~Intern();
		Intern(Intern const &other);
		Intern & operator=(Intern const &other);
		AForm* makeForm(std::string nameForm, std::string target);
};

#endif