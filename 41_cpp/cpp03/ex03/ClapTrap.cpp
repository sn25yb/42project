#include "ClapTrap.hpp"

/* ************************************************************************** */
/*                           ORTHODOX CANONICAL FORM                          */
/* ************************************************************************** */

ClapTrap::ClapTrap()
{
	this->classname = "[ClapTrap]";
	this->name = "Default";
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << this->classname << this->name << OCCF0 << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& claptrap)
{
	*this = claptrap;
	std::cout << this->classname << this->name << OCCF1 << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& claptrap)
{
	this->classname = claptrap.classname;
	this->name = claptrap.name;
	this->hit_points = claptrap.hit_points;
	this->energy_points = claptrap.energy_points;
	this->attack_damage = claptrap.attack_damage;
	std::cout << this->classname << this->name << OCCF2 << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << this->classname << this->name << OCCF3 << std::endl;
}

/* ************************************************************************** */
/*                               CONSTRUCTOR                                  */
/* ************************************************************************** */

ClapTrap::ClapTrap(std::string _name)
{
	this->classname = "[ClapTrap]";
	this->name = _name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << this->classname << this->name << OCCF0 << std::endl;
}

/* ************************************************************************** */
/*                                  FUNCTION                                  */
/* ************************************************************************** */

void ClapTrap::attack(const std::string& target)
{
	unsigned int	pre_ep;

	pre_ep = this->energy_points;
	if (pre_ep && this->hit_points) 
	{
		this->energy_points--;
		std::cout << NOTICE << this->classname << this->name << " attacks " << target << "!" << std::endl;
	}
	else
		std::cout << NOTICE << this->classname << this->name << " can't attack." << std::endl;
	std::cout  << NSPACE << this->classname << this->name << " energy_points: " << pre_ep << " > " << this->energy_points << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int	pre_hp;

	pre_hp = this->hit_points;
	if (pre_hp >= amount)
		this->hit_points -= amount;
	else 
		this->hit_points = 0;
	std::cout << NSPACE << this->classname << this->name << " is damaged!" << std::endl;
	std::cout << NSPACE << this->classname << this->name << " hit_points: " << pre_hp << " > " << this->hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int	pre_ep;
	unsigned int 	pre_hp;

	pre_ep = this->energy_points;
	pre_hp = this->hit_points;
	if (pre_ep && pre_hp) 
	{
		this->energy_points--;
		this->hit_points += amount;
		std::cout << NOTICE << this->classname << this->name << " repairs itself." << std::endl;
	}
	else
		std::cout << NOTICE << this->classname << this->name << " can't repair." << std::endl;
	std::cout << NSPACE << this->classname << this->name << " energy_points: " << pre_ep << " > " << this->energy_points << std::endl;
	std::cout << NSPACE << this->classname << this->name << " hit_points: " << pre_hp << " > " << this->hit_points << std::endl;
}

void ClapTrap::getstat()
{
	std::cout << "================================" << std::endl;
	std::cout << "    classname:" << this->classname << std::endl;
	std::cout << "         name:" << this->name << std::endl;
	std::cout << "    hit_point:" << this->hit_points << std::endl;
	std::cout << "energy_points:" << this->energy_points << std::endl;
	std::cout << "attack_damage:" << this->attack_damage << std::endl;
	std::cout << "================================" << std::endl;
}
