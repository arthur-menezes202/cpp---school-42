#include <iostream>
#include <ctype.h>

using namespace std;

int main(int ac, char **av) {
	int x;

	if(ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	for (int y = 1; y < ac; y ++)
	{
		x = 0;
		while (av[y][x] != '\0') {
			std::cout << (char) toupper(av[y][x]);
			x ++;
		}
	}
	std::cout << "\n";
	return 0;
}