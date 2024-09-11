#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "PhoneBook class is constructed\n";
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook class is destructed\n";
}

void	PhoneBook::add_phonebook(void)
{
	this->contacts[this->index % PBMAX].add_contact(index % PBMAX);
	this->index++;
}

void	PhoneBook::display_phonebook(void)
{
	int index;

	index = 0;
	while (index < this->index && index < PBMAX)
	{
		if (index == 0)
			this->contacts[index].display_contact(TRUE);
		else 
			this->contacts[index].display_contact(FALSE);
		index++;
	}
}

void	PhoneBook::search_phonebook(void)
{
	int	index;

	while (1)
	{
		index = std::stoi(this->contacts[0].get_contact("index"));
		if (index < this->index && index < PBMAX)
		{
			this->contacts[index].display_contact(TRUE);
			break ;
		}
		else
			std::cout << "invalid index." << std::endl;
	}
}

int main(int argc, char **argv)
{
	PhoneBook	phonebook;
	std::string command;

	(void) argc;
	(void) argv;
	while (1)
	{
		std::cout << "Enter Command: 1.ADD 2.SEARCH 3.EXIT" << std::endl;
		std::cin >> command;
		if (std::cin.eof())
		{
			std::cerr << std::endl << "EOF encountered. Exiting..." << std::endl;
			exit(0);
		}
		// if (std::cin.fail())
		// {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		// }
		if (command == "ADD")
			phonebook.add_phonebook();
		else if (command == "SEARCH")
		{
			phonebook.display_phonebook();
			printf("pass\n");
			phonebook.search_phonebook();
		}
		else if (command == "EXIT")
			exit(0);
	}
	return (0);
}
