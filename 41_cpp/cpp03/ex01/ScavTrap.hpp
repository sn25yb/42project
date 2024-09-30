#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		std::string classname;
	public:
		/* ORTHODOX CANONICAL FORM */
						ScavTrap();
						ScavTrap(const ScavTrap& scavtrap);
		ScavTrap&		operator = (const ScavTrap& scavtrap);
		virtual			~ScavTrap();
		/* CONSTRUCTOR */
						ScavTrap(std::string name);
		/* FUNCTION */
		void			guardGate();
		virtual void	attack(const std::string& target);
		virtual void	getstat();
};

#endif
