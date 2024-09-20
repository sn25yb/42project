#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string		name;
		unsigned int	hit_points;
		unsigned int	energy_points;
		unsigned int	attack_damage;
	public:
		/* ORTHODOX CANONICAL FORM */
		ClapTrap();
		ClapTrap(const ClapTrap& clap);
		ClapTrap& operator = (const ClapTrap& clap);
		~ClapTrap();
		/* CONSTRUCTOR */
		ClapTrap(std::string name);
		/* FUNCTION */
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
