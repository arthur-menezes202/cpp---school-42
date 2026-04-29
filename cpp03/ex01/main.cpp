#include "ClapTrap.hpp"
#include <iostream>

int main() {
    std::cout << "--- CONSTRUÇÃO ---" << std::endl;
    ClapTrap hero("Ash");
    ClapTrap bandit("Badass Psycho");

    std::cout << "\n--- ROUND 1: ATAQUE E DANO ---" << std::endl;
    hero.attack("Badass Psycho");
    bandit.takeDamage(5); // Bandit perde 5 HP

    std::cout << "\n--- ROUND 2: REPARO ---" << std::endl;
    bandit.beRepaired(3); // Bandit recupera 3 HP

    std::cout << "\n--- ROUND 3: ESGOTANDO ENERGIA ---" << std::endl;
    // O ClapTrap começa com 10 de energia. Vamos gastar o resto.
    for (int i = 0; i < 10; i++) {
        hero.attack("alvo de treino");
    }
    std::cout << "\n--- ROUND 4: MORTE ---" << std::endl;
    bandit.takeDamage(20); // Dano maior que o HP atual
    bandit.beRepaired(10); // Não deve funcionar, ele está "morto"
    bandit.attack("Ash");  // Não deve funcionar

    std::cout << "\n--- DESTRUIÇÃO ---" << std::endl;
    return 0;
}