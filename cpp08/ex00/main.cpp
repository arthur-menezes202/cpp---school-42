#include "easyfind.hpp"

int main() {
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	try {
		std::vector<int>::iterator it = easyfind(v, 10);
		std::cout << "Achado: " << *it << std::endl;
		easyfind(v, 50);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
