NAME = brain

CPP = g++
CPPFLAG = -std=c++98
WFLAG = -Wall -Wextra -Werror

SRC = ./main.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CPPFLAG) $(WFLAG) $^ -o $@

%.o: %.cpp
	$(CPP) $(CPPFLAG) $(WFLAG) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean :
	rm -rf $(OBJ)
	rm -rf $(NAME)

re : 
	rm -rf $(OBJ)
	rm -rf $(NAME)
	make all

.PHONY: all clean fclean re
