#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	// std::cout << "[Ice]" << this->type << OCCF0 << std::endl;
}

Ice::Ice(const Ice& ice) : AMateria("ice")
{
	this->type = ice.type;
	// std::cout << "[Ice]" << this->type << OCCF1 << std::endl;
}

Ice&	Ice::operator= (const Ice& ice)
{
	this->type = ice.type;
	// std::cout << "[Ice]" << this->type << OCCF2 << std::endl;
	return (*this);
}

Ice::~Ice()
{
	// std::cout << "[Ice]" << this->type << OCCF3 << std::endl;
}

/* FUNCTION */
Ice	*Ice::clone() const
{
	Ice *new_ice = new Ice();
	return (new_ice);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() <<" *" << std::endl;
}
