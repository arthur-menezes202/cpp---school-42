#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
	std::cout << "=== TEST 1: Int Array and Initialization ===" << std::endl;
	unsigned int n = 5;
	Array<int> intArray(n);
	
	std::cout << "Array size: " << intArray.size() << std::endl;
	for (unsigned int i = 0; i < intArray.size(); i++) {
		std::cout << "Value at [" << i << "]: " << intArray[i] << " (should be 0)" << std::endl;
	}

	std::cout << "\n=== TEST 2: Deep Copy (Copy Constructor) ===" << std::endl;
	Array<int> copyArray(intArray);
	
	std::cout << "Original [0]: " << intArray[0] << " | Copy [0]: " << copyArray[0] << std::endl;
	copyArray[0] = 42;
	std::cout << "After modifying copy -> Original [0]: " << intArray[0] << " (still 0?) | Copy [0]: " << copyArray[0] << std::endl;
	if (intArray[0] != copyArray[0])
		std::cout << "SUCCESS: Deep copy verified!" << std::endl;
	else
		std::cout << "FAILURE: Shallow copy detected!" << std::endl;
	std::cout << "\n=== TEST 3: Assignment Operator ===" << std::endl;
	Array<int> assignArray;
	assignArray = intArray;
	std::cout << "Assigned array size: " << assignArray.size() << std::endl;
	std::cout << "Assigned [4]: " << assignArray[4] << std::endl;
	std::cout << "\n=== TEST 4: Out of Bounds Exception ===" << std::endl;
	try {
		std::cout << "Trying to access index 10 in an array of size 5..." << std::endl;
		std::cout << intArray[10] << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << "\n=== TEST 5: String Array ===" << std::endl;
	Array<std::string> strArray(3);
	strArray[0] = "42";
	strArray[1] = "Porto";
	strArray[2] = "Lisboa";
	
	for (unsigned int i = 0; i < strArray.size(); i++) {
		std::cout << "String [" << i << "]: " << strArray[i] << std::endl;
	}

	return 0;
}