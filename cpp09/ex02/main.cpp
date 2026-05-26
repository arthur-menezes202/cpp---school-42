#include <iostream>
#include <exception>
#include "PmergeMe.hpp"
int main(int ac, char **av) {
    if(ac < 2)
    {
        std::cout << "error, no arguments" << std::endl;
        return 0;
    }
    try {
        PmergeMe p(av, ac);
        std::vector<int> v = p.getVElemtents();
        p.sortVector(v);
        std::deque<int> d = p.getDElemtents();
        p.sortDeque(d);
        p.printSort(v);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}