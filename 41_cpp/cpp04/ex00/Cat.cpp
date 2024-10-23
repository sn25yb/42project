#include "Cat.hpp"

/* ************************************************************************** */
/*                           ORTHODOX CANONICAL FORM                          */
/* ************************************************************************** */

Cat::Cat()
{
	this->classname = "[Cat]";
	this->type = "Cat";
	std::cout << this->classname << this->type << OCCF0 << std::endl;
}

Cat::Cat(const Cat& cat) : Animal()
{
	this->classname = cat.classname;
	this->type = cat.type;
	std::cout << this->type << OCCF1 << std::endl;
}

Cat& Cat::operator= (const Cat& cat)
{
	this->type = cat.classname;
	this->type = cat.type;
	std::cout << this->type << OCCF2 << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << this->classname << this->type << OCCF3 << std::endl;
}

/* ************************************************************************** */
/*                                  FUNCTION                                  */
/* ************************************************************************** */

void	Cat::makeSound() const
{
	std::cout << this->type << ": Meow Meow!" <<std::endl;
}
