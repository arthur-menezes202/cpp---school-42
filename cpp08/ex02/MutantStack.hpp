#include <iostream>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
		MutantStack(){}
		~MutantStack(){}
		MutantStack(MutantStack const &other){*this = other;}
		MutantStack & operator=(MutantStack const &other){(void)other; return *this;}
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin() { return this->c.begin(); }
        iterator end()   { return this->c.end(); }
};
