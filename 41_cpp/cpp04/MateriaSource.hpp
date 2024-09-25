#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource
{
	private:
		/* data */
	public:
		/* ORTHODOX CANONICAL FORM */
		MateriaSource();
		MateriaSource(const MateriaSource& materia_source);
		MateriaSource& operator =(const MateriaSource& materia_source);
		~MateriaSource();
		/* FUNCTION */
		void learnMateria(AMateria*);
		createMateria(std::string const &);
};

MateriaSource::MateriaSource()
{

}

MateriaSource::MateriaSource(const MateriaSource& materia_source)
{

}

MateriaSource& MateriaSource::operator =(const MateriaSource& materia_source)
{
	
}


MateriaSource::~MateriaSource()
{

}

void MateriaSource::learnMateria(AMateria*)
{

}


		createMateria(std::string const &);

#endif