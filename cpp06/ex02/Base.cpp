#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base()
{

}
Base::~Base()
{

}

Base * generate(void)
{
    int sort = std::rand() % 3;
	std::cout << sort << std::endl;
	switch (sort) {
	case 0:
		return new A();
		break;
	case 1: 
		return new B();
		break;
	default:
		return new C();
		break;
	}
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p)) std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p)) std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (...) {}
}
