#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

# define OCCF0 " constructor called."
# define OCCF1 " copy constructor called."
# define OCCF2 " copy assignment operator called."
# define OCCF3 " destructor called."
# define NOTICE " ❯ "
# define NSPACE "   "

class ClapTrap
{
	private:
		std::string		classname;
	protected:
		std::string		name;
		unsigned int	hit_points;
		unsigned int	energy_points;
		unsigned int	attack_damage;
	public:
		/* ORTHODOX CANONICAL FORM */
		ClapTrap();
		ClapTrap(const ClapTrap& clap);
		ClapTrap& operator = (const ClapTrap& clap);
		virtual ~ClapTrap();
		/* CONSTRUCTOR */
		ClapTrap(std::string name);
		/* FUNCTION */
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
