#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "OCCF.hpp"
# include "ICharacter.hpp"

# define NSPACE "   "

class ICharacter;

class AMateria
{
	protected:
		std::string			type;
	public:
		/* ORTHODOX CANONICAL FORM */
							AMateria();
							AMateria(const AMateria& amateria);
		AMateria&			operator= (const AMateria& amateria);
		virtual				~AMateria();
		/* CONSTRUCTOR */
							AMateria(std::string const& _type);
		/* FUNCTION - get, set */
		std::string const&	getType() const;
		/* FUNCTION */
		virtual				AMateria* clone() const = 0;
		virtual void		use(ICharacter& target);
};
#endif