#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{	
	std::cout << "[ScavTrap] Default constructor called" << std::endl;
	this->name = "Default";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap)
{
	std::cout << "[ScavTrap] " << scavtrap.name << "Copy constructor called" << std::endl;
	*this = scavtrap;
}
ScavTrap& ScavTrap::operator = (const ScavTrap& scavtrap)
{
	std::cout << "[ScavTrap] " << scavtrap.name << "Copy assignment operator called" << std::endl;
	this->name = scavtrap.name;
	this->hit_points = scavtrap.hit_points;
	this->energy_points = scavtrap.energy_points;
	this->attack_damage = scavtrap.attack_damage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] " << this->name << " destructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "[ScavTrap] " << name << " constructor called" << std::endl;
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

void ScavTrap::attack(const std::string& target)
{
	unsigned int	pre_ep;

	pre_ep = this->energy_points;
	if (pre_ep)
	{
		this->energy_points--;
		std::cout << " ❯ ScavTrap " << this->name << " attacks " << target << "!" << std::endl;
	}
	else
		std::cout << " ❯ ScavTrap " << this->name << " can't attack." << std::endl;
	std::cout  << "   ScavTrap " << this->name << " energy_points: " << pre_ep << " > " << this->energy_points << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "[ScavTrap]" << this->name << " is now in Gatekeeper mode" << std::endl;
}