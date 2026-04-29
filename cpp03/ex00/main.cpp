#include "ClapTrap.hpp"
#include <iostream>

int main() {
    std::cout << "--- contructor ---" << std::endl;
    ClapTrap hero("Ash");
    ClapTrap bandit("Badass Psycho");

    std::cout << "\n--- ROUND 1: attack and demage ---" << std::endl;
    hero.attack("Badass Psycho");
    bandit.takeDamage(5);

    std::cout << "\n--- ROUND 2: Repaired ---" << std::endl;
    bandit.beRepaired(3);

    std::cout << "\n--- ROUND 3: dont have energy ---" << std::endl;
    for (int i = 0; i < 10; i++) {
        hero.attack("alvo de treino");
    }
    std::cout << "\n--- ROUND 4: die ---" << std::endl;
    bandit.takeDamage(20);
    bandit.beRepaired(10);
    bandit.attack("Ash");

    std::cout << "\n--- Destructor ---" << std::endl;
    return 0;
}