NAME = harl

CXX = g++
CXXFLAG = -std=c++98 -pedantic
WFALG = -Wall -Wextra -Werror

SRC = \
	./Harl.cpp\
	./main.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAG) $(WFALG) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAG) $(WFALG) -c $< -o $@
	
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
