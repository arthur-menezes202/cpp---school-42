#include "iter.hpp"

int main( void ) {

	const std::string arr[] = {"A", "B", "C"};
	int arrInt[] = {1, 2, 3, 4, 5};
	double arrDouble[] = {1.1, 2.2, 3.3};
	std::string arrString[] = {"eschool", "42"};

	::iter(arrInt, 5, ft_execute<int>);
	::iter(arrDouble, 3, ft_execute<double>);
	::iter(arrString, 2, ft_execute<std::string>);
	return 0;
}