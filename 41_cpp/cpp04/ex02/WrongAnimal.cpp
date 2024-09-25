#include "WrongAnimal.hpp"

/* ************************************************************************** */
/*                           ORTHODOX CANONICAL FORM                          */
/* ************************************************************************** */

WrongAnimal::WrongAnimal()
{
	this->classname = "[WrongAnimal]";
	this->type = "WrongAnimal";
	std::cout << this->classname << this->type << OCCF0 << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& Wronganimal)
{
	*this = Wronganimal;
	std::cout << Wronganimal.type << OCCF1 << std::endl;
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& wronganimal)
{
	this->type = wronganimal.type;
	std::cout << wronganimal.type << OCCF2 << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << this->classname << this->type << OCCF3 << std::endl;
}

/* ************************************************************************** */
/*                                  FUNCTION                                  */
/* ************************************************************************** */

void	WrongAnimal::makeSound() const
{
	std::cout << this->type << ": WrongAnimal WrongAnimal!" <<std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}
