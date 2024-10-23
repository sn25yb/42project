#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		std::string		classname;
		Brain			*brain;
	public:
		/* ORTHODOX CANONICAL FORM */
						Cat();
						Cat(const Cat& cat);
		Cat&			operator= (const Cat& cat);
		virtual			~Cat();
		/* FUNCTION */
		virtual void	makeSound() const;
};

#endif