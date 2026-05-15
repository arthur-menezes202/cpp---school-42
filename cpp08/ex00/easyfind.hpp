#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <iterator> 
#include <vector>

template <typename T>
typename T::iterator easyfind(T &container, int valorProcurado) {
	typename T::iterator it = std::find(container.begin(), container.end(), valorProcurado);
	if (it == container.end()) {
		throw std::runtime_error("Valor não encontrado no container.");
	}
	return it;
}

#endif