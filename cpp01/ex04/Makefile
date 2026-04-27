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

test: all
	@mkdir -p $(TEST_DIR)
	@echo "Create file tests..."
	
	@# Test 1: simple
	@echo "banana" > $(TEST_DIR)/test1.txt
	./$(TARGET) $(TEST_DIR)/test1.txt "ana" "XXX"
	
	@# Test 2: Multiple occurrences
	@echo "gato gato cao gato" > $(TEST_DIR)/test2.txt
	./$(TARGET) $(TEST_DIR)/test2.txt "gato" "rato"
	
	@# Test 3: Empty lines and spaces
	@echo -e "line 1\n\nline 3" > $(TEST_DIR)/test3.txt
	./$(TARGET) $(TEST_DIR)/test3.txt "line" "phase"

.PHONY: all clean fclean re