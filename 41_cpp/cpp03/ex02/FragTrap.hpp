#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{	
	public:
		const std::string classname = "[FragTrap]";
	public:
		/* ORTHODOX CANONICAL FORM */
		FragTrap();
		FragTrap(const FragTrap& fragTrap);
		FragTrap& operator = (const FragTrap& fragTrap);
		~FragTrap();
		/* CONSTRUCTOR */
		FragTrap(std::string name);

		/* FUNCTION */
		void highFivesGuys(void);

};

FragTrap::FragTrap()
{
	std::cout << this->classname << " Default constructor called" << std::endl;
	this->name = "Default";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& fragTrap)
{

}

FragTrap& FragTrap:: operator = (const FragTrap& fragTrap)
{
	
}

FragTrap::~FragTrap()
{
}

FragTrap::FragTrap(std::string name)
{
	
}

void FragTrap::highFivesGuys(void)
{
	std::cout << this->classname << this->name << "request a positive high fives!" << std::endl;
}


#endif 