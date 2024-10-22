#ifndef FLOOR_HPP
# define FLOOR_HPP

# include "AMateria.hpp"

# define FLOORMAX 50

class Floor
{
	private:
		AMateria	*floor_invetory[FLOORMAX];
		int			len;
	public:
					Floor();
					Floor(const Floor& floor);
		Floor&		operator= (const Floor& floor);
					~Floor();
		void		add_floor_invetory(AMateria *materia);
};

#endif