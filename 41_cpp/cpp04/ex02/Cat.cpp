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

Cat::Cat(const Cat& cat) : AAnimal()
{
	this->classname = cat.classname;
	this->type = cat.type;
	this->brain = new Brain();
	*(this->brain) = *(cat.brain);
	std::cout << this->type << OCCF1 << std::endl;
}

Cat& Cat::operator= (const Cat& cat)
{
	if (this != &cat)
	{
		this->classname = cat.classname;
		this->type = cat.type;
		*(this->brain) = *(cat.brain);
	}
	std::cout << this->type << OCCF2 << std::endl;
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
