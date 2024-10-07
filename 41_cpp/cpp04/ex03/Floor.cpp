#include "Floor.hpp"

Floor::Floor()
{
	// std::cout << "[Floor]" << OCCF0 << std::endl;
}

Floor::Floor(const Floor& floor)
{
	*this = floor;
	// std::cout << "[Floor]" << OCCF1 << std::endl;
}

Floor&	Floor::operator= (const Floor& floor)
{
	if (this != &floor)
	{	
		this->len = floor.len;
		for (int idx = 0; idx < this->len; idx++)
			this->floor_invetory[idx] = floor.floor_invetory[idx]->clone();
	}
	// std::cout << "[Floor]" << OCCF2 << std::endl;
	return (*this);
}

Floor::~Floor()
{
	for (int idx = 0; idx + 1 < this->len; idx++)
		delete this->floor_invetory[idx];
	// std::cout << "[Floor]" << OCCF3 << std::endl;
}

void	Floor::add_floor_invetory(AMateria *materia)
{
	if (this->len < FLOORMAX)
	{
		this->floor_invetory[this->len] = materia;
		this->len++;
	}
}
