CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

NAME   := RPN
OBJDIR   := obj
SRCS     := main.cpp \
			RPN.cpp

OBJS     := $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	@echo "=================================================="
	@echo "          INICIANDO TESTES DO RPN (EX01)          "
	@echo "=================================================="
	@echo ""
	@echo "--- 1. CASOS DE SUCESSO ---"
	@echo -n "Testando \"8 9 *\"             -> Esperado: 72   | Obtido: " && ./$(NAME) "8 9 *"
	@echo -n "Testando \"2 3 + 4 *\"         -> Esperado: 20   | Obtido: " && ./$(NAME) "2 3 + 4 *"
	@echo -n "Testando \"9 8 * 7 + 6 -\"     -> Esperado: 73   | Obtido: " && ./$(NAME) "9 8 * 7 + 6 -"
	@echo -n "Testando \"3 4 -\"             -> Esperado: -1   | Obtido: " && ./$(NAME) "3 4 -"
	@echo -n "Testando \"5 5 -\"             -> Esperado: 0    | Obtido: " && ./$(NAME) "5 5 -"
	@echo ""
	@echo "--- 2. ERROS DE SINTAXE ---"
	@echo -n "Testando \"10 2 +\"            -> Esperado: Error | Obtido: " && ./$(NAME) "10 2 +" || true
	@echo -n "Testando \"1 a +\"             -> Esperado: Error | Obtido: " && ./$(NAME) "1 a +" || true
	@echo -n "Testando \"2.5 3 +\"           -> Esperado: Error | Obtido: " && ./$(NAME) "2.5 3 +" || true
	@echo -n "Testando \"   \"               -> Esperado: Error | Obtido: " && ./$(NAME) "   " || true
	@echo -n "Testando \"\"                 -> Esperado: Error | Obtido: " && ./$(NAME) "" || true
	@echo ""
	@echo "--- 3. ERROS DE LÓGICA DA PILHA ---"
	@echo -n "Testando \"1 2 + +\"           -> Esperado: Error | Obtido: " && ./$(NAME) "1 2 + +" || true
	@echo -n "Testando \"1 2 3 +\"           -> Esperado: Error | Obtido: " && ./$(NAME) "1 2 3 +" || true
	@echo -n "Testando \"+\"                 -> Esperado: Error | Obtido: " && ./$(NAME) "+" || true
	@echo -n "Testando \"5\"                 -> Esperado: Error | Obtido: " && ./$(NAME) "5" || true
	@echo ""
	@echo "--- 4. CASO CRÍTICO ---"
	@echo -n "Testando \"7 0 /\"             -> Esperado: Error | Obtido: " && ./$(NAME) "7 0 /" || true
	@echo ""
	@echo "=================================================="


.PHONY: all clean fclean re test