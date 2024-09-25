#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->classname = "[HumanB]";
	this->name = name;
	this->weapon = NULL; //compiler? c++?
	std::cout << this->classname << this->name << OCCF0 << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << this->classname << this->name << OCCF3 << std::endl;
}

void HumanB::attack(void)
{
	if (this->weapon)
		std::cout << this->classname << this->name << " attacks with their " \
				<< this->weapon->get_classname() << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
	if (this->weapon)
		std::cout << this->weapon->get_classname() << this->weapon->getType() \
				<< " set up for " << this->classname << this->name << "." << std::endl;
}
