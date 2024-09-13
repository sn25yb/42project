#include "Weapon.hpp"

Weapon::Weapon(void)
{

}

Weapon::Weapon(std::string weapon)
{
	this->type = weapon;
	std::cout << " ❯ Weapon [" << this->type << "] is created." << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << " ❯ Weapon [" << this->getType() << "] is destroyed." << std::endl;
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
