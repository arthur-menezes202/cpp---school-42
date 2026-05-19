#include "Span.hpp"
Span::Span()
{
	throw std::runtime_error("No number initilize.");
}
Span::Span(unsigned int n) : _max(n), distanceMin(0), distanceMax(0) {}
Span::~Span() {}
Span::Span(Span const &other)
{
	*this = other;
}

Span & Span::operator=(Span const &other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_max = other._max;
		distanceMin = other.distanceMin;
		distanceMax = other.distanceMax;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if(_vector.size() >= _max)
	{
		throw std::out_of_range("max size");
	}
	_vector.push_back(number);
}

void Span::check()
{
	if(_vector.size() <= 1)
	{
		throw std::out_of_range("No spans could be found.");
	}
}

int Span::shortestSpan()
{
	check();
	std::sort(_vector.begin(), _vector.end());

    int distance = std::numeric_limits<int>::max();
	for (size_t i = 0; i < _vector.size() - 1; ++i) {
        int Mindistancia = std::abs(_vector[i+1] - _vector[i]);
        if (Mindistancia < distance) {
			distanceMin = _vector[i];
			distanceMax = _vector[i+1];
            distance = Mindistancia;
        }
    }
	return distance;
}
int Span::longestSpan()
{
	int itmin = *std::min_element(_vector.begin(), _vector.end());
	int itmax = *std::max_element(_vector.begin(), _vector.end());
	int distance = itmax - itmin;
	return distance;
}

void Span::newNumbers(int n)
{
	for(int i = 0;i < n;i++)
	{
		addNumber(rand());
	}
}

int Span::minEl()
{
	return *std::min_element(_vector.begin(), _vector.end());
}

int Span::maxEl()
{
	return *std::max_element(_vector.begin(), _vector.end());

}

int Span::getDistanceMin()
{
	return distanceMin;
}

int Span::getDistanceMax()
{
	return distanceMax;
}
