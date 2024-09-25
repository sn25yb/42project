#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap :  public ScavTrap, public FragTrap
{
	private:
		std::string classname;
		std::string	name;
	public:
		/* ORTHODOX CANONICAL FORM */
		DiamondTrap();
		DiamondTrap(const DiamondTrap& diamondtrap);
		DiamondTrap& operator= (const DiamondTrap& diamontrap);
		~DiamondTrap();
		/* CONSTRUCTOR */
		DiamondTrap(std::string name);
		/* FUNCTION */
		void	whoAmI();
		void	getstat();
};

#endif
