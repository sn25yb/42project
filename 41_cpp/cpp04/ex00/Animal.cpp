#include "Animal.hpp"

/* ************************************************************************** */
/*                           ORTHODOX CANONICAL FORM                          */
/* ************************************************************************** */

Animal::Animal()
{
	this->classname = "[Animal]";
	this->type = "Animal";
	std::cout << this->classname << this->type << OCCF0 << std::endl;
}

Animal::Animal(const Animal& animal)
{
	*this = animal;
	std::cout << animal.type << OCCF1 << std::endl;
}

Animal& Animal::operator= (const Animal& animal)
{
	this->type = animal.type;
	std::cout << animal.type << OCCF2 << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << this->classname << this->type << OCCF3 << std::endl;
}

/* ************************************************************************** */
/*                                  FUNCTION                                  */
/* ************************************************************************** */

void	Animal::makeSound() const
{
	std::cout << this->type << ": Animal Animal!" <<std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}
