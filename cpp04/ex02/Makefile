CXX      := c++
CXXFLAGS := 
# CXXFLAGS := -Wall -Wextra -Werror -std=c++98

TARGET   := animal
OBJDIR   := obj
SRCS     := main.cpp \
            Animal.cpp \
            WrongAnimal.cpp \
            WrongCat.cpp \
            Cat.cpp \
            Dog.cpp \
            Brain.cpp


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

.PHONY: all clean fclean re