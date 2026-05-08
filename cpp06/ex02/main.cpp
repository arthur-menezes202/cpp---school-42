#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Protótipos das funções solicitadas no exercício
Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {
    // Semeia o gerador de números aleatórios
    std::srand(std::time(NULL));

    std::cout << "=== TEST 1: RANDOM GENERATION AND IDENTIFICATION ===" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "Test #" << i + 1 << ":" << std::endl;
        Base* randomObject = generate();
        
        std::cout << "Identify via pointer:   ";
        identify(randomObject);
        
        std::cout << "Identify via reference: ";
        identify(*randomObject);
        
        std::cout << "------------------------------------------" << std::endl;
        delete randomObject;
    }

    std::cout << "\n=== TEST 2: SPECIFIC IDENTIFICATION ===" << std::endl;
    
    Base* a = new A();
    Base* b = new B();
    Base* c = new C();

    std::cout << "Should be A: "; identify(a);
    std::cout << "Should be B: "; identify(b);
    std::cout << "Should be C: "; identify(c);

    delete a;
    delete b;
    delete c;

    return 0;
}