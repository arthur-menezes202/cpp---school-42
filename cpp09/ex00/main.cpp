#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
double valueBitcoin(const std::string date, double b, std::map<std::string, double> MyData);
std::map<std::string, double> createConteiner();
void readfileBitcoin(std::string nameFile);

int main(int argc, char **argv) {
	if(argc != 2)
	{
		std::cout << "error in arguments: nameFile" << std::endl;
		return 0;
	}
	std::map<std::string, double> MyData = createConteiner();
	try {
		readfileBitcoin(argv[1]);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
