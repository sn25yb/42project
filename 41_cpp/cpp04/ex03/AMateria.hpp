#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class AMateria
{
	private:
		std::string classname;
	protected:
		std::string type;
	public:
		/* ORTHODOX CANONICAL FORM */
		AMateria();
		AMateria(const AMateria& amateria);
		AMateria& operator= (const AMateria& amateria);
		~AMateria();
		/* CONSTRUCTOR */
		AMateria(std::string const & type);
		/* FUNCTION */
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif