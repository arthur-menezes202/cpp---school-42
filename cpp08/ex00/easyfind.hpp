#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <iterator> 
#include <vector>
#include <sstream>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int valueFind) {
	typename T::iterator it = std::find(container.begin(), container.end(), valueFind);
	if (it == container.end()) {
		std::ostringstream oss;
		oss << "Value not found in container: " << valueFind << ".";
		throw std::runtime_error(oss.str());
	}
	return it;
}

#endif