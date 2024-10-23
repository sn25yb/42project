#include "AAnimal.hpp"

/* ************************************************************************** */
/*                           ORTHODOX CANONICAL FORM                          */
/* ************************************************************************** */

AAnimal::AAnimal()
{
	this->classname = "[AAnimal]";
	this->type = "AAnimal";
	std::cout << this->classname << this->type << OCCF0 << std::endl;
}

AAnimal::AAnimal(const AAnimal& animal)
{
	this->classname = animal.classname;
	this->type = animal.type;
	std::cout << this->type << OCCF1 << std::endl;
}

AAnimal& AAnimal::operator= (const AAnimal& animal)
{
	this->classname = animal.classname;
	this->type = animal.type;
	std::cout << this->type << OCCF2 << std::endl;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << this->classname << this->type << OCCF3 << std::endl;
}

/* ************************************************************************** */
/*                                  FUNCTION                                  */
/* ************************************************************************** */

std::string	AAnimal::getType() const
{
	return (this->type);
}
