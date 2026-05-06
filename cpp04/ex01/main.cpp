#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
	std::cout << "--- TEST 1: Instantiating Concrete Classes ---" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " says: ";
	j->makeSound();
	
	std::cout << i->getType() << " says: ";
	i->makeSound();

	delete j;
	delete i;

	std::cout << "\n--- TEST 2: The Abstract Challenge ---" << std::endl;
	Animal* pack[4];
	pack[0] = new Dog();
	pack[1] = new Cat();
	pack[2] = new Dog();
	pack[3] = new Cat();

	std::cout << "\n--- Pack Sound Test ---" << std::endl;
	for (int k = 0; k < 4; k++) {
		pack[k]->makeSound();
	}

	std::cout << "\n--- Cleaning up pack ---" << std::endl;
	for (int k = 0; k < 4; k++) {
		delete pack[k];
	}

	return 0;
}