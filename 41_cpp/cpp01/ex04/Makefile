NAME = replace

CXX = g++
CXXFLAG = -std=c++98 -pedantic
WFLAG = -Wall -Wextra -Werror

SRC = \
	./main.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAG) $(WFLAG) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAG) $(WFLAG) -c $< -o $@

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
