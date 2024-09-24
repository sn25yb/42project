NAME = harl

CPP = g++
CPPFLAG = -std=c++98 
WFALG = -Wall -Wextra -Werror

SRC = \
	./Harl.cpp\
	./main.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CPPFLAG) $(WFALG) $^ -o $@

%.o: %.cpp
	$(CPP) $(CPPFLAG) $(WFALG) -c $< -o $@
	
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
