#include "Contact.hpp"
#include <limits>

//입출력스트림
//클래스

Contact::Contact()
{
	std::cout << "Contact class is constructed" << std::endl;
}

Contact::~Contact()
{
	std::cout << "Contact class is desstructed" << std::endl;
}
#include <stdio.h>

std::string	Contact::get_contact(const std::string str)
{
	std::string	field;

	while (1)
	{
		std::cout << "Please enter " << str << " ❯ ";
		getline(std::cin, field);
		// printf(">%s\n", field.c_str());
		if (std::cin.eof())
		{
			std::cerr << std::endl << "EOF encountered. Exiting..." << std::endl;
			exit(0);
		}
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (!field.empty())
			break ;
		std::cerr << str << " is empty. Please try again." << std::endl;
	}
	return (field);
}

void	Contact::add_contact(int index)
{
	std::string	field;

	this->index = index;
	field = get_contact(FN);
	this->FirstName = field;
	field = get_contact(LN);
	this->LastName = field;
	field = get_contact(NN);		
	this->NickName = field;
	field = get_contact(PN);
	this->PhoneNumber = field;
	field = get_contact(DS);
	this->DarkestSecret = field;
}

void	Contact::display_column(std::string str) 
{
	if (str.length() > LEN)
		str = str.substr(0, LEN);
	std::cout << std::right << std::setw(LEN) << std::setfill(FILL) << str << SEP;
}

void	Contact::display_attribute(void)
{
	display_column("index");
	display_column(FN);
	display_column(LN);
	display_column(NN);
	std::cout << std::endl;
	std::cout << "=============================================" << std::endl;
}

void	Contact::display_contact(int attribute_on)
{	
	if (attribute_on == TRUE)
		display_attribute();
	display_column(std::to_string(this->index));
	display_column(this->FirstName);
	display_column(this->LastName);
	display_column(this->NickName);
	std::cout << std::endl;
}
