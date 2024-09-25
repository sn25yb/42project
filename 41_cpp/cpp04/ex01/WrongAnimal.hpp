#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

# define OCCF0 " constructor called."
# define OCCF1 " copy constructor called."
# define OCCF2 " copy assignment operator called."
# define OCCF3 " destructor called."
# define NOTICE " ❯ "
# define NSPACE "   "

class WrongAnimal
{
	private:
		std::string	classname;
	protected:
		std::string	type;
	public:
		/* ORTHODOX CANONICAL FORM */
		WrongAnimal();
		WrongAnimal(const WrongAnimal& wronganimal);
		WrongAnimal& operator= (const WrongAnimal& wronganimal);
		virtual~WrongAnimal();
		/* FUNCTION */
		void			makeSound() const;
		std::string		getType() const;
};

#endif
