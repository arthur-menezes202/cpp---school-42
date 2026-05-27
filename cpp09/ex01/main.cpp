#include "RPN.hpp"

int main(int ac, char **av)
{
	if(ac != 2)
	{
		std::cout << "arguments not aviable.";
		return 0;
	}
	RPN myListNumbers(av[1]);
	try{
		myListNumbers.calculate();
		std::cout << "Result: " << myListNumbers.getResult() << std::endl;

	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
