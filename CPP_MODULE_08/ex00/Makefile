NAME = easyfind
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = $(FILES)

FILES = main.cpp \

HEADER =  easyfind.hpp easyfind.tpp \

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all