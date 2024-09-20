#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		const std::string classname = "[ScavTrap]";
	public:
		/* ORTHODOX CANONICAL FORM */
		ScavTrap();
		ScavTrap(const ScavTrap& scavtrap);
		ScavTrap& operator = (const ScavTrap& scavtrap);
		~ScavTrap();
		/* CONSTRUCTOR */
		ScavTrap(std::string name);
		/* FUNCTION */
		void guardGate();
		void attack(const std::string& target);
};

#endif
