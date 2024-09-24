NAME = account

CPP = g++
CPPFLAG = -std=c++98
WFLAG = -Wall -Wextra -Werror

SRC = ./tests.cpp ./Account.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CPPFLAG) $^ -o $@

%.o: %.cpp
	$(CPP) $(CPPFLAG) -c $< -o $@

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
