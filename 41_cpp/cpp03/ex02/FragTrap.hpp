#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{	
	private:
		std::string		classname;
	public:
		/* ORTHODOX CANONICAL FORM */
						FragTrap();
						FragTrap(const FragTrap& fragtrap);
		FragTrap&		operator = (const FragTrap& fragtrap);
		virtual			~FragTrap();
		/* CONSTRUCTOR */
						FragTrap(std::string name);
		/* FUNCTION */
		void			highFivesGuys(void);
		virtual void	getstat();
};

#endif 
