#include "Dog.hpp"

/* ************************************************************************** */
/*                           ORTHODOX CANONICAL FORM                          */
/* ************************************************************************** */

Dog::Dog()
{
	this->classname = "[Dog]";
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << this->classname << this->type << OCCF0 << std::endl;
}

Dog::Dog(const Dog& dog)
{
	*this = dog;
	std::cout << dog.type << OCCF1 << std::endl;
}

Dog& Dog::operator= (const Dog& dog)
{
	this->type = dog.type;
	this->brain = new Brain(*(dog.brain));
	std::cout << dog.type << OCCF2 << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << this->classname << this->type << OCCF3 << std::endl;
}

/* ************************************************************************** */
/*                                  FUNCTION                                  */
/* ************************************************************************** */

void	Dog::makeSound() const
{
	std::cout << this->type << ": Bark Bark!" <<std::endl;
}