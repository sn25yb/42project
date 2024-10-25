#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
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
		void			showbrain() const;
};

#endif