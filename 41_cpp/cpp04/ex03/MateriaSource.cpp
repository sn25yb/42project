#include "MateriaSource.hpp"

/* ORTHODOX CANONICAL FORM */
MateriaSource::MateriaSource()
{
	// std::cout << "[MateriaSource]" << OCCF0 << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& materia_source)
{
	if (this != &materia_source)
	{
		for (int idx = 0; idx < MNUMS; idx++)
			delete this->sources[idx];
		for (int idx = 0; idx < MNUMS; idx++)
			if (materia_source.sources[idx])
				this->sources[idx] = materia_source.sources[idx];
	}
	// std::cout << "[MateriaSource]" << OCCF1 << std::endl;
}

MateriaSource& MateriaSource::operator= (const MateriaSource& materia_source)
{
	if (this != &materia_source)
	{
		for (int idx = 0; idx < MNUMS; idx++)
			delete this->sources[idx];
		for (int idx = 0; idx < MNUMS; idx++)
			if (materia_source.sources[idx])
				this->sources[idx] = materia_source.sources[idx];
	}
	// std::cout << "[MateriaSource]" << OCCF2 << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int idx = 0; idx < MNUMS; idx++)
		delete this->sources[idx];
	// std::cout << "[MateriaSource]" << OCCF3 << std::endl;
}

/* FUNCTION */
void	MateriaSource::learnMateria(AMateria* materia)
{
	for (int idx = 0; idx < MNUMS; idx++)
	{
		if (!this->sources[idx])
		{
			this->sources[idx] = materia;
			// std::cout <<"learnMateria " << this->sources[idx]->getType() << std::endl;
			break ;
		}
		else if (idx + 1 == MNUMS)
		{
			delete materia;
			std::cout << "You learned 4 materias already." << std::endl;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const& _type)
{
	AMateria *new_materia;

	if (_type != "cure" && _type != "ice")
		return (NULL);
	new_materia = NULL;
	for (int idx = 0; idx < MNUMS; idx++)
	{	
		if (this->sources[idx] && this->sources[idx]->getType() == _type)
		{	
			new_materia = this->sources[idx]->clone();
			// std::cout <<"creatMatearia " << this->sources[idx]->getType() << std::endl;
			break ; 
		}
		else if (idx + 1 == MNUMS)
			std::cout << "MateriaSource does not have the type of materia." << std::endl;
	}
	return (new_materia);
}