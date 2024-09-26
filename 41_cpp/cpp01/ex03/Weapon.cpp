#include "Weapon.hpp"

Weapon::Weapon(void)
{
	this->classname = "[Weapon]";
	this->type = "Default";
	std::cout << this->classname << this->type << OCCF0 << std::endl;
}

Weapon::Weapon(std::string weapon)
{
	this->classname = "[Weapon]";
	this->type = weapon;
	std::cout << this->classname << this->type << OCCF0 << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << this->classname << this->type << OCCF3 << std::endl;
}

std::string Weapon::getType(void)
{
	const std::string &ref_type = this->type;

	return (ref_type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}

std::string Weapon::get_classname()
{
	return (this->classname);
}
