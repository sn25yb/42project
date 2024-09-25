#include "PhoneBook.hpp"

/* ************************************************************************** */
/*                               CONSTRUCTOR                                  */
/* ************************************************************************** */

PhoneBook::PhoneBook()
{
	this->classname = "[PhoneBook]";
	std::cout << this->classname << OCCF0 << std::endl;
}

/* ************************************************************************** */
/*                                DESTRUCTOR                                  */
/* ************************************************************************** */

PhoneBook::~PhoneBook()
{
	std::cout << this->classname << OCCF3 << std::endl;
}

/* ************************************************************************** */
/*                                  FUNCTION                                  */
/* ************************************************************************** */

/* add_phonebook */
void	PhoneBook::add_phonebook(void)
{
	this->contacts[this->addindex % PAGE].add_contact(this->addindex %PAGE);
	this->addindex++;
}

/* display_phonebook */
void	PhoneBook::display_phonebook(void)
{
	int index;

	index = 0;
	while (index < this->addindex && index < PAGE)
	{
		if (index == 0)
			this->contacts[index].display_contact(TRUE);
		else 
			this->contacts[index].display_contact(FALSE);
		index++;
	}
}

/* search_phonebook */
void	PhoneBook::search_phonebook(void)
{
	std::string str;
	int			index;

	while (1)
	{
		str = get_index("index");
		std::stringstream ss(str);
		ss >> index;
		if (ss.eof() && !ss.fail() && 0 <= index && index < PAGE)
		{
			if (index < this->addindex)
				this->contacts[index].display_contact(TRUE);
			else 
				std::cerr << "empty index." << std::endl;
			break ;
		}
		else
			std::cerr << "invalid index." << std::endl;
	}
}

std::string	PhoneBook::get_index(const std::string str)
{
	std::string	index;

	while (1)
	{
		std::cout << "Please enter " << str << NOTICE;
		getline(std::cin, index);
		if (std::cin.eof())
		{
			std::cerr << std::endl << "EOF encountered. Exiting..." << std::endl;
			return (NULL);
		}
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (!index.empty())
			break;
		else
			std::cerr << str << " is empty. Please try again." << std::endl;
	}
	return (index);
}