CXX      := c++
CXXFLAGS := 
# CXXFLAGS := -Wall -Wextra -Werror -std=c++98

NAME   := PmergeMe
OBJDIR   := obj
SRCS     := main.cpp \
			PmergeMe.cpp

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

.PHONY: all clean fclean re