#include "PhoneBook.hpp"

static void			Phone();
static std::string	ft_getline();

int main(void)
{
	Phone();
	return (0);
}

static void	Phone()
{
	PhoneBook	phonebook;
	std::string command;
	
	while (1)
	{
		std::cout << NOTICE << "Enter Command: ADD | SEARCH | EXIT" << std::endl;
		command = ft_getline();
		if (command == "ADD")
			phonebook.add_phonebook();
		else if (command == "SEARCH")
		{
			phonebook.display_phonebook();
			phonebook.search_phonebook();
		}
		else if (command == "EXIT")
			exit(0);
	}
}

static std::string	ft_getline()
{
	std::string command;

	getline(std::cin, command);
	if (std::cin.eof())
	{
		std::cerr << std::endl << "EOF encountered. Exiting..." << std::endl;
		exit(0);
	}
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return (command);
}