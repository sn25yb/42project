#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	private:
		std::string type;
	public:
					Weapon(void);
					Weapon(std::string weapon);
					~Weapon(void);
		std::string	getType(void);
		void 		setType(std::string type);
};



#endif
