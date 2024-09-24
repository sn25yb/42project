#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	this->name = name;
	this->weapon = weapon;
	std::cout << " ❯ HumanA [" << this->name << "] is created."<< std::endl;
	std::cout << "   Weapon [" << this->weapon.getType() << "] set up for HumanA [" << this->name << "]." << std::endl;
}

HumanA::~HumanA()
{
	std::cout << " ❯ HumanA [" << this->name << "] is destroyed." << std::endl;
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << "." << std::endl;
}
