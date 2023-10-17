NAME = megaphone

FLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = megaphone.cpp

SRCS_DIR = .
BUILD_DIR = .

OBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:%.cpp=%.o))
SRCS := $(addprefix $(SRCS_DIR)/, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(FLAGS) $(SRCS) -o $(NAME)
#	c++ $(OBJS) -o $(NAME)

#$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.cpp
#	c++ $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

valgrind:
	clang++ $(FLAGS) -g $(SRCS) -o $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONE: all clean fclean re valgrind