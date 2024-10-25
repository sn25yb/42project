#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
		std::string	classname;
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