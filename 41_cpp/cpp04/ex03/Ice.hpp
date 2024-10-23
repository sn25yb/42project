#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria 
{
	public:
		/* ORTHODOX CANONICAL FORM */
						Ice();
						Ice(const Ice& ice);
		Ice&			operator= (const Ice& ice);
		virtual			~Ice();
		/* FUNCTION */
		virtual Ice*	clone() const;
		virtual void	use(ICharacter& target);
};


#endif