#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		/* ORTHODOX CANONICAL FORM */
					WrongCat();
					WrongCat(const WrongCat& wrongcat);
		WrongCat&	operator= (const WrongCat& wrongcat);
		virtual		~WrongCat();
		/* FUNCTION */
		void		makeSound() const;
};

#endif 