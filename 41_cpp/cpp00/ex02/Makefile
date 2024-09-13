NAME = account

CXX = g++
WFLAG = -Wall -Wextra -Werror
CXXFLAG = -std=c++98 -pedantic

SRC = ./tests.cpp ./Account.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAG) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAG) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean : 
	rm -f $(OBJ)
	rm -f $(NAME)

re : 
	rm -f $(OBJ)
	rm -f $(NAME)
	make all

./PHONY: all clean fclean re
