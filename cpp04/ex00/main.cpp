/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 18:47:05 by armeneze          #+#    #+#             */
/*   Updated: 2026/05/04 18:52:10 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
	std::cout << "--- TEST 1: Standard Polymorphism (Correct implementation) ---" << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\nChecking Types:" << std::endl;
	std::cout << "j type: " << j->getType() << std::endl;
	std::cout << "i type: " << i->getType() << std::endl;

	std::cout << "\nChecking Sounds (Should match the derived class):" << std::endl;
	std::cout << "Cat i sound: ";
	i->makeSound(); // Expected: Cat sound

	std::cout << "Dog j sound: ";
	j->makeSound(); // Expected: Dog sound

	std::cout << "Animal meta sound: ";
	meta->makeSound(); // Expected: Default Animal sound

	std::cout << "\nDeleting Animals (Virtual Destructors Check):" << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << "\n--- TEST 2: Wrong Classes (No virtual methods) ---" << std::endl;
	
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "\nChecking Sounds (Polymorphism will FAIL here):" << std::endl;
	std::cout << "WrongCat sound: ";
	wrongCat->makeSound(); // Expected: WrongAnimal sound (because it's NOT virtual)
	
	std::cout << "WrongAnimal sound: ";
	wrongMeta->makeSound();

	std::cout << "\nDeleting Wrong Classes:" << std::endl;
	delete wrongMeta;
	delete wrongCat; // Warning: Only WrongAnimal destructor will be called!

	return 0;
}