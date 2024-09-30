#include "DiamondTrap.hpp"

/* ************************************************************************** */
/*                           ORTHODOX CANONICAL FORM                          */
/* ************************************************************************** */

DiamondTrap::DiamondTrap(): classname("DiamonTrap"), name("Default")
// DiamondTrap::DiamondTrap(): ClapTrap("Default_clap_name"), classname("DiamonTrap"), name("Default")
{
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	ClapTrap::name = name + "_clap_name";
	std::cout << this->classname << this->name << OCCF0 << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondtrap) : ClapTrap(), ScavTrap(), FragTrap()
{
	*this = diamondtrap;
	std::cout << this->classname << this->name << OCCF1 << std::endl;
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap& diamondtrap)
{
	this->ClapTrap::name = diamondtrap.ClapTrap::name;
	this->classname = diamondtrap.classname;
	this->name = diamondtrap.name;
	this->hit_points = diamondtrap.hit_points;
	this->energy_points = diamondtrap.energy_points;
	this->attack_damage = diamondtrap.attack_damage;
	std::cout << this->classname << this->name << OCCF2 << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << this->classname << this->name << OCCF3 << std::endl;	
}

/* ************************************************************************** */
/*                               CONSTRUCTOR                                  */
/* ************************************************************************** */

// DiamondTrap::DiamondTrap(std::string _name): ClapTrap(_name + "_clap_name")
DiamondTrap::DiamondTrap(std::string _name)
{
	this->classname = "[DiamondTrap]";
	this->name = _name;
	this->hit_points = FragTrap::hit_points;
	// this->energy_points = ScavTrap::energy_points;
	this->energy_points = 50;
	this->attack_damage = FragTrap::attack_damage;
	ClapTrap::name = name + "_clap_name";
	std::cout << this->hit_points << std::endl;
	std::cout << this->classname << this->name << OCCF0 << std::endl;
}

/* ************************************************************************** */
/*                                  FUNCTION                                  */
/* ************************************************************************** */

void DiamondTrap::whoAmI()
{
	std::cout << "================================" << std::endl;
	std::cout << "   class name:" << this->classname << std::endl;
	std::cout << "         name:" << this->name << std::endl;
	std::cout << "ClapTrap name:" << ClapTrap::name << std::endl;
	std::cout << "================================" << std::endl;
}

void DiamondTrap::getstat()
{
	std::cout << "================================" << std::endl;
	std::cout << " ClapTrapname:" << ClapTrap::name << std::endl;
	std::cout << "    classname:" << this->classname << std::endl;
	std::cout << "         name:" << this->name << std::endl;
	std::cout << "    hit_point:" << this->hit_points << std::endl;
	std::cout << "energy_points:" << this->energy_points << std::endl;
	std::cout << "attack_damage:" << this->attack_damage << std::endl;
	std::cout << "================================" << std::endl;
}
