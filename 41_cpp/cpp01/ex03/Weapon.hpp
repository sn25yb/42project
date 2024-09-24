#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

# define OCCF0 " constructor called."
# define OCCF3 " destructor called."
# define NOTICE " ❯ "
# define NSPACE "   "

class Weapon
{
	private:
		std::string classname;
		std::string type;
	public:
					Weapon(void);
					Weapon(std::string weapon);
					~Weapon(void);
		std::string	getType(void);
		void 		setType(std::string type);
		std::string get_classname();
};



#endif
