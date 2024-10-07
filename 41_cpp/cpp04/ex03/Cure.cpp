#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	// std::cout << "[Cure]" << this->type << OCCF0 << std::endl;
}

Cure::Cure(const Cure& cure) : AMateria("cure")
{
	*this = cure;
	// std::cout << "[Cure]" << this->type << OCCF1 << std::endl;
}

Cure& Cure::operator= (const Cure& cure)
{
	(void) cure;
	// std::cout << "[Cure]" << this->type << OCCF2 << std::endl;
	return (*this);
}

Cure::~Cure()
{
	// std::cout << "[Cure]" << this->type << OCCF3 << std::endl;
}

/* FUNCTION */
Cure *Cure::clone() const
{
	Cure *new_cure = new Cure;
	return (new_cure);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
