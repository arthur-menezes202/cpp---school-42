#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    Intern  someRandomIntern;
    Bureaucrat boss("The Boss", 1);
    AForm*  rrf;
    std::cout << "--- TEST 1: Intern creates a Robotomy Request ---" << std::endl;
    rrf = someRandomIntern.makeForm("Robotomy Request", "Bender");
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    std::cout << "\n--- TEST 2: Intern creates a Shrubbery Creation ---" << std::endl;
    rrf = someRandomIntern.makeForm("Shrubbery Creation", "Home");
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    std::cout << "\n--- TEST 3: Intern creates a Presidential Pardon ---" << std::endl;
    rrf = someRandomIntern.makeForm("Presidential Pardon", "Arthur Dent");
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    std::cout << "\n--- TEST 4: Intern tries to create an unknown form ---" << std::endl;
    rrf = someRandomIntern.makeForm("coffee request", "Intern");
    if (rrf) {
        delete rrf;
    } else {
        std::cout << "Intern failed as expected: Form not found." << std::endl;
    }

    return 0;
}
