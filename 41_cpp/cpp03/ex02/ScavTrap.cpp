#include "ScavTrap.hpp"

/* ************************************************************************** */
/*                           ORTHODOX CANONICAL FORM                          */
/* ************************************************************************** */

ScavTrap::ScavTrap()
{	
	this->classname = "[ScavTrap]";
	this->name = "Default";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << this->classname << this->name << OCCF0 << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap) : ClapTrap()
{
	*this = scavtrap;
	std::cout << this->classname << this->name << OCCF1 << std::endl;
}
ScavTrap& ScavTrap::operator = (const ScavTrap& scavtrap)
{
	this->classname = scavtrap.classname;
	this->name = scavtrap.name;
	this->hit_points = scavtrap.hit_points;
	this->energy_points = scavtrap.energy_points;
	this->attack_damage = scavtrap.attack_damage;
	std::cout << this->classname << this->name << OCCF2 << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << this->classname << this->name << OCCF3 << std::endl;
}

/* ************************************************************************** */
/*                               CONSTRUCTOR                                  */
/* ************************************************************************** */

ScavTrap::ScavTrap(std::string name)
{
	this->classname = "[ScavTrap]";
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << this->classname << this->name << OCCF0 << std::endl;
}
/* ************************************************************************** */
/*                                  FUNCTION                                  */
/* ************************************************************************** */

void ScavTrap::attack(const std::string& target)
{
	unsigned int	pre_ep;

	pre_ep = this->energy_points;
	if (pre_ep)
	{
		this->energy_points--;
		std::cout << NOTICE << this->classname << this->name << " attacks " << target << "!" << std::endl;
	}
	else
		std::cout << NOTICE << this->classname << this->name << " can't attack." << std::endl;
	std::cout  << NSPACE << this->classname << this->name << " energy_points: " << pre_ep << " > " << this->energy_points << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << NOTICE << this->classname << this->name << " is now in Gatekeeper mode." << std::endl;
}

void ScavTrap::getstat()
{
	std::cout << "================================" << std::endl;
	std::cout << "    classname:" << this->classname << std::endl;
	std::cout << "         name:" << this->name << std::endl;
	std::cout << "    hit_point:" << this->hit_points << std::endl;
	std::cout << "energy_points:" << this->energy_points << std::endl;
	std::cout << "attack_damage:" << this->attack_damage << std::endl;
	std::cout << "================================" << std::endl;
}
