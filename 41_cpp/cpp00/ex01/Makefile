NAME = phonebook

CXX = g++
CXXFLAG = -Wall -Wextra -Werror -std=c++98 -pedantic
###-pedatic###
#: This flag enables strict adherence to the chosen C language standard, 
#  providing additional warnings for non-standard or questionable code constructs

SRC = ./PhoneBook.cpp ./Contact.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAG) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAG) -c $< -o $@

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
