NAME = harl

CXX = g++
WARNING = -Wall -Wextra -Werror
CXXFLAG = -std=c++98 -pedantic
COMPILE = $(CXX) $(WARNING) $(CXXFLAG)

SRC = \
	./main.cpp \
	./harl.cpp \
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(COMPILE) $^ -o $@

%.o: %.cpp
	$(COMPILE) -c $< -o $@

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
