#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string classname;
		std::string name;
		Weapon		&weapon;
	public:
					HumanA(std::string name, Weapon &weapon);
					~HumanA(void);
		void		attack(void);
		void		setWeapon(Weapon &weapon);
};


#endif
