NAME = FragTrap
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = $(FILES)

FILES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

HEADER = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all