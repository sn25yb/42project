#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		std::string		classname;
		Brain			*brain;
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