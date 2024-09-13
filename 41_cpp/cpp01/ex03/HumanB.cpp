#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	std::cout << " ❯ HumanB [" << this->name << "] is created." << std::endl;
}
HumanB::~HumanB(void)
{
	std::cout << " ❯ HumanB [" << this->name << "] is destroyed." << std::endl;
}
void HumanB::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon weapon)
{
	this->weapon = &weapon;
	std::cout << " ❯ Weapon [" << this->weapon->getType() << "] set up for HumanB [" << this->name << "]." << std::endl;
}
