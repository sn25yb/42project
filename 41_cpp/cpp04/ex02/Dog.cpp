#include "Dog.hpp"

/* ************************************************************************** */
/*                           ORTHODOX CANONICAL FORM                          */
/* ************************************************************************** */

Dog::Dog()
{
	this->classname = "[Dog]";
	this->type = "Dog";
	std::cout << this->classname << this->type << OCCF0 << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog& dog) : AAnimal()
{
	this->classname = dog.classname;
	this->type = dog.type;
	this->brain = new Brain();
	*(this->brain) = *(dog.brain);
	std::cout << dog.type << OCCF1 << std::endl;
}

Dog& Dog::operator= (const Dog& dog)
{
	if (this != &dog)
	{
		this->classname = dog.classname;
		this->type = dog.type;
		*(this->brain) = *(dog.brain);
	}
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
