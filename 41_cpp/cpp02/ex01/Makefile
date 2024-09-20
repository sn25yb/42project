NAME = fixed

CPP = g++
CPPFLAGS = -std=c++98 -pedantic
WFLAGS = -Wall -Wextra -Werror

SRC = \
	./Fixed.cpp \
	./main.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CPPFLAGS) $(WFLAGS) $^ -o $@

%.o : %.cpp
	$(CPP) $(CPPFLAGS) $(WFLAGS) -c $< -o $@

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
