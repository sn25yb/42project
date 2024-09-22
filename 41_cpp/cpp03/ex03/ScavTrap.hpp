#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#define SCAVTRAP "[ScavTrap]"

class ScavTrap : public ClapTrap
{
	private:
		std::string classname;
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
