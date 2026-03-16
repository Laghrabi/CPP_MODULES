NAME = template
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = $(FILES)

FILES = main.cpp \

HEADER =  Array.hpp Array.tpp \

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all