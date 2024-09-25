#include "Cat.hpp"

/* ************************************************************************** */
/*                           ORTHODOX CANONICAL FORM                          */
/* ************************************************************************** */

Cat::Cat()
{
	this->classname = "[Cat]";
	this->type = "Cat";
	std::cout << this->classname << this->type << OCCF0 << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat& cat)
{
	*this = cat;
	std::cout << cat.type << OCCF1 << std::endl;
}

Cat& Cat::operator= (const Cat& cat)
{
	this->type = cat.type;
	this->brain = new Brain(*(cat.brain));
	std::cout << cat.type << OCCF2 << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << this->classname << this->type << OCCF3 << std::endl;
}

/* ************************************************************************** */
/*                                  FUNCTION                                  */
/* ************************************************************************** */

void	Cat::makeSound() const
{
	std::cout << this->type << ": Meow Meow!" <<std::endl;
}


void	Cat::print_brain()
{
	this->brain->print_brain();
}
