#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include "cpp.hpp"

class WrongAnimal
{
	private:
		std::string	classname;
	protected:
		std::string	type;
	public:
		/* ORTHODOX CANONICAL FORM */
		WrongAnimal();
		WrongAnimal(const WrongAnimal& wronganimal);
		WrongAnimal& operator= (const WrongAnimal& wronganimal);
		virtual~WrongAnimal();
		/* FUNCTION */
		void			makeSound() const;
		std::string		getType() const;
};

#endif
