CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

TARGET   := replace
OBJDIR   := obj
SRCS     := main.cpp
TEST_DIR := tests_dir

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
	rm -rf $(TEST_DIR)


re: fclean all



.PHONY: all clean fclean re