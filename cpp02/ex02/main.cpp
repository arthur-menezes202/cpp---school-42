#include <iostream>
 #include "Fixed.hpp"

 void printHeader(std::string title) {
 std::cout << "\n--- " << title << " ---" << std::endl;
 }

 int main( void ) {
 Fixed a;
 Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
 std::cout << a << std::endl;
 std::cout << ++a << std::endl;
 std::cout << a << std::endl;
 std::cout << a++ << std::endl;
 std::cout << a << std::endl;
 std::cout << b << std::endl;
 std::cout << Fixed::max( a, b ) << std::endl;

 printHeader("Operator Attribute ");
 Fixed c(10);
 Fixed d(10.01f);
 Fixed e(10);
 std::cout << "c (10) >  d (10.01): " << (c > d) << " (Esperado: 0)" << std::endl;
 std::cout << "c (10) <  d (10.01): " << (c < d) << " (Esperado: 1)" << std::endl;
 std::cout << "c (10) >= e (10):    " << (c >= e) << " (Esperado: 1)" << std::endl;
 std::cout << "c (10) <= e (10):    " << (c <= e) << " (Esperado: 1)" << std::endl;
 std::cout << "c (10) == e (10):    " << (c == e) << " (Esperado: 1)" << std::endl;
 std::cout << "c (10) != d (10.01): " << (c != d) << " (Esperado: 1)" << std::endl;

 printHeader("Operator Arithmetic");
 Fixed f(2);
 Fixed g(4);
 std::cout << "Addition:       4 + 2 = " << (g + f) << std::endl;
 std::cout << "Subtraction:    4 - 2 = " << (g - f) << std::endl;
 std::cout << "Subtraction:    2 - 4 = " << (f - g) << std::endl;
 std::cout << "Multiplication: 4 * 2 = " << (g * f) << std::endl;
 std::cout << "Division:       4 / 2 = " << (g / f) << std::endl;
 std::cout << "Division:       1 / 2 = " << (Fixed(1) / Fixed(2)) << std::endl;

 printHeader("INCREMENT / DECREMENT");
 Fixed h(5);
 std::cout << "h inicial:   " << h << std::endl;
 std::cout << "h-- (pos):   " << h-- << " (Deve mostrar 5)" << std::endl;
 std::cout << "h após pos:  " << h << std::endl;
 std::cout << "--h (pre):   " << --h << " (Deve mostrar ~4.99)" << std::endl;

 printHeader("MIN / MAX (Const and no-Const)");
 Fixed i(42);
 Fixed j(21);
 const Fixed ci(42.42f);
 const Fixed cj(21.21f);
 std::cout << "Min (normal): " << Fixed::min(i, j) << std::endl;
 std::cout << "Max (normal): " << Fixed::max(i, j) << std::endl;
 std::cout << "Min (const):  " << Fixed::min(ci, cj) << std::endl;
 std::cout << "Max (const):  " << Fixed::max(ci, cj) << std::endl;

 return 0;
 }
