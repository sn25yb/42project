#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
# define MNUMS 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria		*sources[MNUMS];
	public:
		/* ORTHODOX CANONICAL FORM */
						MateriaSource();
						MateriaSource(const MateriaSource& materia_source);
		MateriaSource&	operator= (const MateriaSource& materia_source);
						~MateriaSource();
		/* FUNCTION */
		void			learnMateria(AMateria* materia);
		AMateria*		createMateria(std::string const& _type );
};

#endif