/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 02:30:57 by armeneze          #+#    #+#             */
/*   Updated: 2026/05/08 02:45:23 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "--- Test 1: Form Grade Construction ---" << std::endl;
    try {
        Form high("Top Secret", 0, 15);
    } catch (std::exception &e) {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Successful Signing ---" << std::endl;
    try {
        Bureaucrat boss("The Boss", 5);
        Form tax("Tax Form", 10, 20);
        
        std::cout << boss << std::endl;
        std::cout << tax << std::endl;
        
        boss.signForm(tax);
        std::cout << tax << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Failed Signing (Grade too low) ---" << std::endl;
    try {
        Bureaucrat intern("Intern", 140);
        Form nuclear("Nuclear Launch", 1, 1);
        
        std::cout << intern << std::endl;
        std::cout << nuclear << std::endl;
        
        intern.signForm(nuclear);
        std::cout << nuclear << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 4: Signing already signed form ---" << std::endl;
    try {
        Bureaucrat mid("Manager", 50);
        Form vacation("Vacation Request", 100, 100);
        
        mid.signForm(vacation);
        mid.signForm(vacation); // Já está assinado
    } catch (std::exception &e) {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    return 0;
}