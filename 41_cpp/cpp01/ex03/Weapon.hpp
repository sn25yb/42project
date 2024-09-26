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
		/* CONSTRUCTOR & DESTRUCTOR */
							Weapon(void);
							Weapon(std::string weapon);
							~Weapon(void);
		/* FUNCTION (42) */
		const std::string&	getType(void);
		void 				setType(std::string type);
		/* FUNCTION */
		std::string			get_classname();
};



#endif
