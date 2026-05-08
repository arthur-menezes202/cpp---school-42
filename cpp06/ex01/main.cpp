#include "Serializer.hpp"
#include <iostream>

int main() {
	Data myData;
	myData.id = 42;
	myData.name = "scholl 42";
	myData.value = 3.14f;
	std::cout << "=== SERIALIZATION TEST ===" << std::endl;
	std::cout << "Original Pointer: " << &myData << std::endl;
	std::cout << "Original Data: ID[" << myData.id << "] Name[" << myData.name << "]" << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	intptr_t raw = Serializer::serialize(&myData);
	std::cout << "Serialized (intptr_t): " << raw << std::endl;
	std::cout << "Serialized (hex): 0x" << std::hex << raw << std::dec << std::endl;
	Data* ptr = Serializer::deserialize(raw);
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Deserialized Pointer: " << ptr << std::endl;
	if (ptr == &myData) {
		std::cout << "SUCCESS: Pointers match!" << std::endl;
	} else {
		std::cout << "FAILURE: Pointers are different!" << std::endl;
	}
	std::cout << "Deserialized Data: ID[" << ptr->id << "] Name[" << ptr->name << "]" << std::endl;

	if (ptr->id == myData.id && ptr->name == myData.name) {
		std::cout << "SUCCESS: Data integrity preserved!" << std::endl;
	} else {
		std::cout << "FAILURE: Data corrupted!" << std::endl;
	}
    return 0;
}