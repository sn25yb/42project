NAME = animal

CPP = c++
CPPFLAGS = -std=c++98
WFLAGS = -Wall -Wextra -Werror

SRC = \
	./Animal.cpp \
	./Dog.cpp \
	./Cat.cpp \
	./WrongAnimal.cpp \
	./WrongCat.cpp \
	./Brain.cpp \
	./main.cpp 
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CPPFLAGS) $(WFLAGS) $^ -o $@

%.o : %.cpp
	$(CPP) $(CPPFLAGS) $(WFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ)
	rm -rf $(NAME)

re:
	rm -rf $(OBJ)
	rm -rf $(NAME)
	make all

.PHONY: all clean fclean re  