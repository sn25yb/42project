#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
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
		void			showbrain() const;
};

#endif