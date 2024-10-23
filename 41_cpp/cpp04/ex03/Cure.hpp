#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		/* ORTHODOX CANONICAL FORM */
						Cure();
						Cure(const Cure& cure);
		Cure&			operator= (const Cure& cure);
		virtual			~Cure();
		/* FUNCTION */
		virtual Cure*	clone() const;
		virtual void	use(ICharacter& target);
};

#endif