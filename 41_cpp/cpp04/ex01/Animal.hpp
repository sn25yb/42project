#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "cpp.hpp"

class Animal
{
	private:
		std::string	classname;
	protected:
		std::string	type;
	public:
		/* ORTHODOX CANONICAL FORM */
		Animal();
		Animal(const Animal& animal);
		Animal& operator= (const Animal& animal);
		virtual ~Animal();
		/* FUNCTION */
		virtual void	makeSound() const;
		std::string		getType() const;
};


#endif
