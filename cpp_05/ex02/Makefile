# Makefile to build the FormExecution executable 
# Author: sbocanci
# Date: 06.11.2023

NAME = FormExecution

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g

SRCS = main.cpp \
	src/Bureaucrat.cpp \
	src/AForm.cpp \
	src/ShrubberyCreationForm.cpp \
	src/RobotomyRequestForm.cpp \
	src/PresidentialPardonForm.cpp

OBJS = $(SRCS:.cpp=.o)

# this is called by default when you just type make
# it will call the recipes for the executable
all: $(NAME)

# recipe to build the executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# recipe to compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# recipe to cleans the object files
clean:
	rm -rf $(OBJS)

# recipe to cleans the object files and the executable
fclean: clean
	rm -rf $(NAME) *_shrubbery

# recipe to cleans the object files and the executable
re: fclean all

# compiles with clang and runs with valgrind
# to pass the ARGS variable to the makefile use:
# make valgrind ARGS="arg1 arg2 arg3"
valgrind:
	g++ $(FLAGS) -g $(SRCS) -o $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARGS)

.PHONY: all clean fclean re valgrind
