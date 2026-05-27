CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

TARGET   := fixed
OBJDIR   := obj
SRCS     := main.cpp \
			Fixed.cpp

OBJS     := $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all
define TEST_MAIN
#include <iostream>\n\
#include "Fixed.hpp"\n\n\
void printHeader(std::string title) {\n\
    std::cout << "\\n--- " << title << " ---" << std::endl;\n\
}\n\n\
int main( void ) {\n\
    Fixed a;\n\
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );\n\
    std::cout << a << std::endl;\n\
    std::cout << ++a << std::endl;\n\
    std::cout << a << std::endl;\n\
    std::cout << a++ << std::endl;\n\
    std::cout << a << std::endl;\n\
    std::cout << b << std::endl;\n\
    std::cout << Fixed::max( a, b ) << std::endl;\n\n\
    printHeader("Operator Attribute ");\n\
    Fixed c(10);\n\
    Fixed d(10.01f);\n\
    Fixed e(10);\n\
    std::cout << "c (10) >  d (10.01): " << (c > d) << " (Esperado: 0)" << std::endl;\n\
    std::cout << "c (10) <  d (10.01): " << (c < d) << " (Esperado: 1)" << std::endl;\n\
    std::cout << "c (10) >= e (10):    " << (c >= e) << " (Esperado: 1)" << std::endl;\n\
    std::cout << "c (10) <= e (10):    " << (c <= e) << " (Esperado: 1)" << std::endl;\n\
    std::cout << "c (10) == e (10):    " << (c == e) << " (Esperado: 1)" << std::endl;\n\
    std::cout << "c (10) != d (10.01): " << (c != d) << " (Esperado: 1)" << std::endl;\n\n\
    printHeader("Operator Arithmetic");\n\
    Fixed f(2);\n\
    Fixed g(4);\n\
    std::cout << "Addition:       4 + 2 = " << (g + f) << std::endl;\n\
    std::cout << "Subtraction:    4 - 2 = " << (g - f) << std::endl;\n\
    std::cout << "Subtraction:    2 - 4 = " << (f - g) << std::endl;\n\
    std::cout << "Multiplication: 4 * 2 = " << (g * f) << std::endl;\n\
    std::cout << "Division:       4 / 2 = " << (g / f) << std::endl;\n\
    std::cout << "Division:       1 / 2 = " << (Fixed(1) / Fixed(2)) << std::endl;\n\n\
    printHeader("INCREMENT / DECREMENT");\n\
    Fixed h(5);\n\
    std::cout << "h inicial:   " << h << std::endl;\n\
    std::cout << "h-- (pos):   " << h-- << " (Deve mostrar 5)" << std::endl;\n\
    std::cout << "h após pos:  " << h << std::endl;\n\
    std::cout << "--h (pre):   " << --h << " (Deve mostrar ~4.99)" << std::endl;\n\n\
    printHeader("MIN / MAX (Const and no-Const)");\n\
    Fixed i(42);\n\
    Fixed j(21);\n\
    const Fixed ci(42.42f);\n\
    const Fixed cj(21.21f);\n\
    std::cout << "Min (normal): " << Fixed::min(i, j) << std::endl;\n\
    std::cout << "Max (normal): " << Fixed::max(i, j) << std::endl;\n\
    std::cout << "Min (const):  " << Fixed::min(ci, cj) << std::endl;\n\
    std::cout << "Max (const):  " << Fixed::max(ci, cj) << std::endl;\n\n\
    return 0;\n\
}
endef
export TEST_MAIN

test:
	@echo "$$TEST_MAIN" > main.cpp
	@make re
	@./$(TARGET)

.PHONY: all clean fclean re