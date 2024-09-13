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

int ft_isinteger(std::string str)
{
	std::istringstream	iss;
	int					integer;

	iss.str(str);
	iss >> integer;
	return (!iss.fail() && iss.eof());
}

std::string	Contact::get_contact(const std::string str, int intopt)
{
	std::string	field;

	while (1)
	{
		std::cout << "Please enter " << str << " ❯ ";
		getline(std::cin, field);
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
		{
			if ((intopt == FALSE && !field.empty()) || (intopt == TRUE && ft_isinteger(field) == TRUE))
				break;
			else if (intopt == TRUE && ft_isinteger(field) == FALSE)
				std::cerr << str << " is not number. Please try again." << std::endl;
		}
		else
			std::cerr << str << " is empty. Please try again." << std::endl;
	}
	return (field);
}

void	Contact::add_contact(int index)
{
	std::string	field;

	this->index = index;
	field = get_contact(FN, FALSE);
	this->FirstName = field;
	field = get_contact(LN, FALSE);
	this->LastName = field;
	field = get_contact(NN, FALSE);		
	this->NickName = field;
	field = get_contact(PN, TRUE);
	this->PhoneNumber = field;
	field = get_contact(DS, FALSE);
	this->DarkestSecret = field;
}

void	Contact::display_column(std::string column)
{
	if (column.length() > LEN)
		column = column.substr(0, LEN);
	std::cout << std::right << std::setw(LEN) << std::setfill(FILL) << column << SEP;
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
	std::stringstream cIndex;

	if (attribute_on == TRUE)
		display_attribute();
	cIndex.str(std::string());
	cIndex << index;
	display_column(cIndex.str());
	display_column(this->FirstName);
	display_column(this->LastName);
	display_column(this->NickName);
	std::cout << std::endl;
}
