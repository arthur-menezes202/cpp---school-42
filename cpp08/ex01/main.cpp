#include "Span.hpp"

int main(void)
{
	unsigned int n = 2;
	Span a(n);
	for(int i = 1;i < 4; i ++)
	{
		try{
			std::cout << "insert:" << i << std::endl;
			a.addNumber(i);
			std::cout << "sucesses." << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	try{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		int size = 1000;
		Span b(size);
		b.newNumbers(size);
		std::cout << b.shortestSpan() << std::endl;
		std::cout << "distance max element: " << b.getDistanceMax() << std::endl;
		std::cout << "distance min element: " << b.getDistanceMin() << std::endl;
		std::cout << "max element: " << b.maxEl() << std::endl;
		std::cout << "min element: " << b.minEl() << std::endl;
		std::cout << b.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}
