/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:54:33 by armeneze          #+#    #+#             */
/*   Updated: 2026/05/01 18:10:19 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include "DiamondTrap.hpp"
#include <iostream>

int main() {
    std::cout << "--- 1. CONSTRUCTION TEST (DUPLICATE VERIFICATION) ---" << std::endl;
    DiamondTrap dt1("D-TP");

    std::cout << "\n--- 2. IDENTITY TEST (whoAmI) ---" << std::endl;
    dt1.whoAmI();

    std::cout << "\n--- 3. ATTRIBUTE AND ATTACK TEST ---" << std::endl;
    dt1.attack("a test dummy");
    
    std::cout << "HP (life Frag): " << dt1.getHP() << " (expected: 100)" << std::endl;
    std::cout << "Energy (life Scav): " << dt1.getEP() << " (expected: 49)" << std::endl;
    std::cout << "Damage (life Frag): " << dt1.getAD() << " (expected: 30)" << std::endl;

    std::cout << "\n--- 4. test of copy ---" << std::endl;
    {
        DiamondTrap dt2("Clone");
        dt2 = dt1;
        std::cout << "copy after assignment: " << std::endl;
        dt2.whoAmI();
    }

    std::cout << "\n--- 5. TEST OF INHERITED SKILLS ---" << std::endl;
    dt1.guardGate();
    dt1.highFivesGuys();

    std::cout << "\n--- 6. UNDOING ---" << std::endl;
    return 0;
}