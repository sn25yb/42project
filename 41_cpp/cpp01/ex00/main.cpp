#include "Zombie.hpp"

int	main()
{
	Zombie stack("stack");
	Zombie *heap = newZombie("heap");
	
	stack.announce();
	heap->announce();
	randomChump("randomChump");
	delete heap;
	return (0);
}
