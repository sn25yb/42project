#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

# define OCCF0 " constructor called."
# define OCCF1 " copy constructor called."
# define OCCF2 " copy assignment operator called."
# define OCCF3 " destructor called."
# define NOTICE " ❯ "
# define NSPACE "   "

class AAnimal
{
	protected:
		std::string		classname;
		std::string		type;
	public:
		/* ORTHODOX CANONICAL FORM */
						AAnimal();
						AAnimal(const AAnimal& animal);
		AAnimal&		operator= (const AAnimal& animal);
		virtual			~AAnimal();
		/* FUNCTION */
		virtual void	makeSound() const = 0;
		std::string		getType() const;
};

#endif
