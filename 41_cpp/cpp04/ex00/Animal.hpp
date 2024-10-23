#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

# define OCCF0 " constructor called."
# define OCCF1 " copy constructor called."
# define OCCF2 " copy assignment operator called."
# define OCCF3 " destructor called."
# define NOTICE " ❯ "
# define NSPACE "   "

class Animal
{
	private:
		std::string		classname;
	protected:
		std::string		type;
	public:
		/* ORTHODOX CANONICAL FORM */
						Animal();
						Animal(const Animal& animal);
		Animal&			operator= (const Animal& animal);
		virtual			~Animal();
		/* FUNCTION */
		virtual void	makeSound() const;
		std::string		getType() const;
};


#endif
