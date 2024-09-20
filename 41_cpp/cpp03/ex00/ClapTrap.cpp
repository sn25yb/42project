#include "ClapTrap.hpp"

/* ************************************************************************** */
/*                           ORTHODOX CANONICAL FORM                          */
/* : Default constructor                                                      */
/* : Copy constructor                                                         */
/* : Copy assignment operator                                                 */
/* : Destructor                                                               */
/* ************************************************************************** */

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	this->name = "Default";
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& claptrap)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = claptrap;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& claptrap)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->name = claptrap.name;
	this->hit_points = claptrap.hit_points;
	this->energy_points = claptrap.energy_points;
	this->attack_damage = claptrap.attack_damage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << this->name << " destructor called" << std::endl;
}

/* ************************************************************************** */
/*                               CONSTRUCTOR                                  */
/* ************************************************************************** */
ClapTrap::ClapTrap(std::string name)
{
	std::cout << name << " constructor called" << std::endl;
	this->name = name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
}


/* ************************************************************************** */
/*                                  FUNCTION                                  */
/* ************************************************************************** */
void ClapTrap::attack(const std::string& target)
{
	unsigned int	pre_ep;

	pre_ep = this->energy_points;
	if (pre_ep)
	{
		this->energy_points--;
		std::cout << " ❯ ClapTrap " << this->name << " attacks " << target << "!" << std::endl;
	}
	else
		std::cout << " ❯ ClapTrap " << this->name << " can't attack." << std::endl;
	std::cout  << "   ClapTrap " << this->name << " energy_points: " << pre_ep << " > " << this->energy_points << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int	pre_hp;

	pre_hp = this->hit_points;
	if (pre_hp >= amount)
		this->hit_points -= amount;
	else 
		this->hit_points = 0;
	std::cout << "   " << this->name << " is damaged!" << std::endl;
	std::cout << "   " << this->name << " hit_points: " << pre_hp << " > " << this->hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int	pre_ep;
	unsigned int 	pre_hp;

	pre_ep = this->energy_points;
	pre_hp = this->hit_points;
	if (pre_ep)
	{
		this->energy_points--;
		this->hit_points += amount;
		std::cout << " ❯ " << this->name << " repairs " << this->name << "." << std::endl;
	}
	else
		std::cout << " ❯ " << this->name << " can't repair." << std::endl;
	std::cout  << "   " << this->name << " energy_points: " << pre_ep << " > " << this->energy_points << std::endl;
	std::cout << "   " << this->name << " hit_points: " << pre_hp << " > " << this->hit_points << std::endl;
}
