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

AAnimal::AAnimal(const AAnimal& Aanimal)
{
	*this = Aanimal;
	std::cout << Aanimal.type << OCCF1 << std::endl;
}

AAnimal& AAnimal::operator= (const AAnimal& Aanimal)
{
	this->type = Aanimal.type;
	std::cout << Aanimal.type << OCCF2 << std::endl;
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
