NAME = interface
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = $(FILES)

FILES = AMateria.cpp Cure.cpp main.cpp Character.cpp Ice.cpp MateriaSource.cpp

HEADER = ICharacter.hpp AMateria.hpp Cure.hpp Character.hpp Ice.hpp MateriaSource.hpp IMateriaSource.hpp

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all