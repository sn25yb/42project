#include "AMateria.hpp"

/* ORTHODOX CANONICAL FORM */
AMateria::AMateria()
{
	this->type = "Default";
	// std::cout << "[AMateria]" << this->type << OCCF0 << std::endl;
}

AMateria::AMateria(const AMateria& amateria)
{
	this->type = amateria.type;
	// std::cout << "[AMateria]" << this->type << OCCF1 << std::endl;
}

AMateria& AMateria::operator= (const AMateria& amateria)
{
	this->type = amateria.type;
	// std::cout << "[AMateria]" << this->type << OCCF2 << std::endl;
	return (*this);
}

AMateria::~AMateria()
{
	// std::cout << "[AMateria]" << this->type << OCCF3 << std::endl;
}

/* CONSTRUCTOR */
AMateria::AMateria(std::string const& _type)
{
	this->type = _type;
}

/* FUNCTION */
std::string const& AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "...ready to use materia to " << target.getName() << std::endl;
}
