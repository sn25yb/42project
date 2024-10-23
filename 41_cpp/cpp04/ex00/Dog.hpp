#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	private:
		std::string		classname;
	public:
		/* ORTHODOX CANONICAL FORM */
						Dog();
						Dog(const Dog& dog);
		Dog&			operator= (const Dog& dog);
		virtual			~Dog();
		/* FUNCTION */
		virtual void	makeSound() const;
};

#endif