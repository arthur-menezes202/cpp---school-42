#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void ft_execute(T const &arg) {

	std::cout << arg << " " << std::endl;
}
template <typename T, typename F>
void iter(T *addr, std::size_t len, F func) {
	std::cout << "start array " << typeid(T).name()  << std::endl;
	for (std::size_t i = 0; i < len; ++i) {
		func(addr[i]);
	}
	std::cout << "end array " << typeid(T).name()  << std::endl;
}


#endif