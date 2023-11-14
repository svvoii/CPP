# Makefile to build the Fixed executable 
# Author: sbocanci
# Date: 02.11.2023

NAME = Fixed

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g

SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:.cpp=.o)

# this is called by default when you just type make
# it will call the recipes for the executable
all: $(NAME)

# recipe to build the executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# recipe to compile .cpp files to .o files
# !! this is not needed because make will do this by default !!
# %.o: %.cpp
#	$(CXX) $(CXXFLAGS) -c $< -o $@

# recipe to cleans the object files
clean:
	rm -rf $(OBJS)

# recipe to cleans the object files and the executable
fclean: clean
	rm -rf $(NAME)

# recipe to cleans the object files and the executable
re: fclean all

# compiles with clang and runs with valgrind
# to pass the ARGS variable to the makefile use:
# make valgrind ARGS="arg1 arg2 arg3"
valgrind:
	g++ $(CXXFLAGS) -g $(SRCS) -o $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARGS)

.PHONY: all clean fclean re valgrind
