#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	this->classname = "[HumanA]";
	this->name = name;
	std::cout << this->classname << this->name << OCCF0 << std::endl;
	std::cout << this->weapon.get_classname() << this->weapon.getType() \
				<< " set up for " << this->classname << this->name << "." << std::endl;
}

HumanA::~HumanA()
{
	std::cout << this->classname << this->name << OCCF3 << std::endl;
}

void HumanA::attack()
{
	std::cout << this->classname << this->name << " attacks with their " \
			<< this->weapon.get_classname() << this->weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon &weapon)
{
	this->weapon = weapon;
	std::cout << this->weapon.get_classname() << this->weapon.getType() \
				<< " set up for " << this->classname << this->name << "." << std::endl;
}
