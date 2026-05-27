#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <ctime> 
class Span
{
	private:
		std::vector<int> _vector;
		unsigned int _max;
		int distanceMin;
		int distanceMax;
	public:
		Span();
		Span(unsigned int n);
		~Span();
		Span(Span const &other);
		Span & operator=(Span const &other);
		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
		int minEl();
		int maxEl();
		void check();
		void newNumbers(int n);
		int getDistanceMin();
		int getDistanceMax();

};

#endif