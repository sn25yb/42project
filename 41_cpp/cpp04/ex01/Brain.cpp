#include "Brain.hpp"

Brain::Brain()
{
	this->classname = "[Brain]";
	for (int index = 0; index < 100; index++)
		this->ideas[index] = index;
	std::cout << this->classname << OCCF0 << std::endl;
	
}

Brain::Brain(const Brain& brain)
{
	*this = brain;
	std::cout << brain.classname << OCCF1 << std::endl;
}

Brain& Brain::operator= (const Brain& brain)
{
	this->classname = brain.classname;
	for (int index = 0; index < 100; index++)
		this->ideas[index] = brain.ideas[index];
	std::cout << brain.classname << OCCF2 << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << this->classname << OCCF3 << std::endl;
}

void	Brain::print_brain()
{
	for (int index = 0; index < 100; index++)
		std::cout << this->ideas[index];
	std::cout << std::endl;
}
