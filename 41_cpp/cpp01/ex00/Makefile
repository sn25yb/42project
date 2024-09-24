NAME = zombie

CPP = g++
CPPFLAG = -std=c++98
WFLAG = -Wall -Wextra -Werror

SRC = \
	./main.cpp \
	./Zombie.cpp \
	./newZombie.cpp \
	./randomChump.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CPPFLAG) $(WFLAG) $^ -o $@

%.o: %.cpp
	$(CPP) $(CPPFLAG) $(WFLAG) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean : 
	rm -f $(OBJ)
	rm -f $(NAME)

re : 
	rm -f $(OBJ)
	rm -f $(NAME)
	make all

.PHONY: all clean fclean re
