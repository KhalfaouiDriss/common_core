NAME = test

SRC = main.cpp Animal.cpp  Cat.cpp Dog.cpp Brain.cpp

CXX = c++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re