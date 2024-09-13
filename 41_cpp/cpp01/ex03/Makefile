NAME = weapon

CXX = g++
CXXFLAG = -std=c++98 -pedantic
WFLAG = -Wall -Wextra -Werror

SRC = \
	./HumanA.cpp \
	./HumanB.cpp \
	./Weapon.cpp \
	./main.cpp
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
