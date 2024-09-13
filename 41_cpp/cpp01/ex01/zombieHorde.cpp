#include "Zombie.hpp"
#include <sstream>

/* Zombie* zombieHorde( int N, std::string name ); in zombieHorde.cpp */
Zombie* zombieHorde(int N, std::string name)
{
	Zombie				*zHorde;
	std::stringstream	zIndex;
	std::string			zName;

	/* allocate N Zombie objects in a single allocation. */
	zHorde = new Zombie[N];	
	for (int index = 0; index < N; index++)
	{
		zIndex.str(std::string());
		zIndex << index;
		zName = name + "_" + zIndex.str();
		/* initialize the zombies, giving each one of them the name passed as parameter. */
		zHorde[index].setName(zName);
		std::cout << " ❯ Zombie " << zName << " is created." << std::endl;
	}
	/* The function returns a pointer to the first zombie.  */
	return (zHorde);
}
