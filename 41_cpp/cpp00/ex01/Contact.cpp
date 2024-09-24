#include "Contact.hpp"

/* ************************************************************************** */
/*                               CONSTRUCTOR                                  */
/* ************************************************************************** */

Contact::Contact()
{
	this->classname = "[Contact]";
	std::cout << this->classname << OCCF0 << std::endl;
}

/* ************************************************************************** */
/*                                DESTRUCTOR                                  */
/* ************************************************************************** */

Contact::~Contact()
{
	std::cout << this->classname << OCCF3 << std::endl;
}

/* ************************************************************************** */
/*                                  FUNCTION                                  */
/* ************************************************************************** */

/* add_contact */
void	Contact::add_contact(int index)
{
	std::string	field;

	this->Cindex = index;
	field = get_contact(FN, FALSE);
	this->firstname = field;
	field = get_contact(LN, FALSE);
	this->lastname = field;
	field = get_contact(NN, FALSE);		
	this->nickname = field;
	field = get_contact(PN, TRUE);
	this->phonenumber = field;
	field = get_contact(DS, FALSE);
	this->darkestsecret = field;
}

std::string	Contact::get_contact(const std::string str, int num_opt)
{
	std::string	field;

	while (1)
	{
		std::cout << "Please enter " << str << NOTICE;
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
			if (!num_opt || (num_opt && valid_phonenumber(field)))
				break;
		}
		else
			std::cerr << str << " is empty. Please try again." << std::endl;
	}
	return (field);
}

int	Contact::valid_phonenumber(std::string str)
{
	long	phonenumber;

	std::stringstream ss(str);
	ss >> phonenumber;
	if (!ss.eof() || ss.fail())
	{	
		std::cerr << str << " is not number. Please try again." << std::endl;
		return (FALSE);
	}
	else if (phonenumber > 999999999999999 || phonenumber < 0)
	{
		std::cerr << "Please enter a positive number less than 15." << std::endl;
		return (FALSE);
	}
	return (TRUE);
}

/* display_contact */
void	Contact::display_contact(int attribute_on)
{	
	std::stringstream ss;

	if (attribute_on == TRUE)
		display_attribute();
	ss.str(std::string());
	ss << this->Cindex;
	display_column(ss.str());
	display_column(this->firstname);
	display_column(this->lastname);
	display_column(this->nickname);
	std::cout << std::endl;
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

void	Contact::display_column(std::string column)
{
	if (column.length() > LEN)
	{	
		column = column.substr(0, LEN - 1);
		std::cout << std::right << std::setw(LEN - 1) << std::setfill(FILL) << column << MORE << SEP;
	}
	else 
		std::cout << std::right << std::setw(LEN) << std::setfill(FILL) << column << SEP;
}
