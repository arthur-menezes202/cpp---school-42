/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 23:41:15 by armeneze          #+#    #+#             */
/*   Updated: 2026/05/06 00:15:33 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "--- Test 1: Valid Bureaucrat ---" << std::endl;
    try {
        Bureaucrat jack("Jack", 2);
        std::cout << jack << std::endl;
        
        jack.upGrade();
        std::cout << "After increment: " << jack << std::endl;
        
        jack.upGrade();
        std::cout << "After increment: " << jack << std::endl;
        std::cout << "This line should not be printed!" << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Grade Too High at Construction ---" << std::endl;
    try {
        Bureaucrat boss("Boss", 0);
        std::cout << boss << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Grade Too Low at Construction ---" << std::endl;
    try {
        Bureaucrat intern("Intern", 151);
        std::cout << intern << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 4: Decrementing to Failure ---" << std::endl;
    try {
        Bureaucrat lazy("Lazy", 149);
        std::cout << lazy << std::endl;
        
        lazy.dowGrade();
        std::cout << "After decrement: " << lazy << std::endl;
        
        lazy.dowGrade();
        std::cout << "This line should not be printed!" << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}