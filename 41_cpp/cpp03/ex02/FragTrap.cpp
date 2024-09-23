#include "FragTrap.hpp"

/* ************************************************************************** */
/*                           ORTHODOX CANONICAL FORM                          */
/* ************************************************************************** */

FragTrap::FragTrap()
{
	this->classname = "[FragTrap]";
	this->name = "Default";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << this->classname << this->name << OCCF0 << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragtrap)
{
	*this = fragtrap;
	std::cout << this->classname << this->name << OCCF1 << std::endl;
}

FragTrap& FragTrap:: operator = (const FragTrap& fragtrap)
{
	this->classname = fragtrap.classname;
	this->name = fragtrap.name;
	this->hit_points = fragtrap.hit_points;
	this->energy_points = fragtrap.energy_points;
	this->attack_damage = fragtrap.attack_damage;
	std::cout << this->classname << this->name << OCCF2 << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << this->classname << this->name << OCCF3 << std::endl;
}

/* ************************************************************************** */
/*                               CONSTRUCTOR                                  */
/* ************************************************************************** */

FragTrap::FragTrap(std::string name)
{
	this->classname = "[FragTrap]";
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << this->classname << this->name << OCCF0 << std::endl;
}

/* ************************************************************************** */
/*                                  FUNCTION                                  */
/* ************************************************************************** */

void FragTrap::highFivesGuys(void)
{
	std::cout << NOTICE << this->classname << this->name << "request a positive high fives!" << std::endl;
}

void FragTrap::getstat()
{
	std::cout << "================================" << std::endl;
	std::cout << "    classname:" << this->classname << std::endl;
	std::cout << "         name:" << this->name << std::endl;
	std::cout << "    hit_point:" << this->hit_points << std::endl;
	std::cout << "energy_points:" << this->energy_points << std::endl;
	std::cout << "attack_damage:" << this->attack_damage << std::endl;
	std::cout << "================================" << std::endl;
}
