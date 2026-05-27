#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::cout << "===== Shrubbery Creation Form =====" << std::endl;

    std::cout << "===== TEST 1: Grade too low to sign =====" << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        ShrubberyCreationForm form("backyard");
        std::cout << form << std::endl;
        intern.signForm(form);
        intern.executeForm(form);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 2: Signed but grade too low to execute =====" << std::endl;
    try {
        Bureaucrat boss("Junior Boss", 140);
        ShrubberyCreationForm form("garden");
        
        boss.signForm(form);
        boss.executeForm(form);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 3: Success Case =====" << std::endl;
    try {
        Bureaucrat mayor("Mayor", 100);
        ShrubberyCreationForm form("park");
        
        mayor.signForm(form);
        mayor.executeForm(form);
        std::cout << "Check your folder for 'park_shrubbery'!" << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }


    std::cout << "===== Robotomy Request Form =====" << std::endl;

	std::srand(std::time(NULL));

    std::cout << "===== TEST 1: Robotomy Grade Requirements =====" << std::endl;
    try {
        Bureaucrat lowLevel("Bender", 80);
        RobotomyRequestForm rob("Fry");
        
        lowLevel.signForm(rob);
        lowLevel.executeForm(rob);
    } catch (std::exception &e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 2: The 50% Chance Test =====" << std::endl;
    try {
        Bureaucrat professor("Professor Farnsworth", 1);
        RobotomyRequestForm rob("Hermes");

        professor.signForm(rob);
        std::cout << "--- Attempt 1 ---" << std::endl;
        professor.executeForm(rob);
        
        std::cout << "--- Attempt 2 ---" << std::endl;
        professor.executeForm(rob);
        
        std::cout << "--- Attempt 3 ---" << std::endl;
        professor.executeForm(rob);
        
        std::cout << "--- Attempt 4 ---" << std::endl;
        professor.executeForm(rob);

    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
	std::cout << "===== Presidential Pardon Form =====" << std::endl;

	std::cout << "===== TEST 1: Executing Unsigned Form =====" << std::endl;

    try {
        Bureaucrat god("God Emperor", 1);
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << "Form status: " << (pardon.getSigned() ? "Signed" : "Not Signed") << std::endl;
        std::cout << "Attempting to execute without signing..." << std::endl;
        god.executeForm(pardon);

    } catch (std::exception &e) {
        std::cout << "Caught Expected Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 2: Sign then Execute (The correct way) =====" << std::endl;

    try {
        Bureaucrat god("God Emperor", 1);
        RobotomyRequestForm robot("Target");

        std::cout << "1. Signing the form..." << std::endl;
        god.signForm(robot);

        std::cout << "2. Executing the form..." << std::endl;
        god.executeForm(robot);
        
        std::cout << "Success! No exception thrown." << std::endl;

    } catch (std::exception &e) {
        std::cout << "Unexpected Exception: " << e.what() << std::endl;
    }

    return 0;
}