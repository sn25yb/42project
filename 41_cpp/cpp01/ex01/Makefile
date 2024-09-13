NAME = zombiehorde

CXX = g++
CXXFLAG = -std=c++98 -pedantic
WFALF = -Wall -Wextra -Werror

SRC = \
	./main.cpp \
	./Zombie.cpp \
	./zombieHorde.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAG) $(WFLAG) $^ -o $@ 

%.o: %.cpp
	$(CXX) $(CXXFLAG) $(WFLAG) -c $< -o $@

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
