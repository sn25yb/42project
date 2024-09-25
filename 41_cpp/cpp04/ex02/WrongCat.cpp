#include "WrongCat.hpp"

/* ************************************************************************** */
/*                           ORTHODOX CANONICAL FORM                          */
/* ************************************************************************** */

WrongCat::WrongCat()
{
	this->classname = "[WrongCat]";
	this->type = "WrongCat";
	std::cout << this->classname << this->type << OCCF0 << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongcat)
{
	*this = wrongcat;
	std::cout << wrongcat.type << OCCF1 << std::endl;
}

WrongCat& WrongCat::operator= (const WrongCat& wrongcat)
{
	this->type = wrongcat.type;
	std::cout << wrongcat.type << OCCF2 << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << this->classname << this->type << OCCF3 << std::endl;
}

/* ************************************************************************** */
/*                                  FUNCTION                                  */
/* ************************************************************************** */

void	WrongCat::makeSound() const
{
	std::cout << this->type << ": Meow Meow!" <<std::endl;
}
