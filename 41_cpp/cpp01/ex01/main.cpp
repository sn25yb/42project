#include "Zombie.hpp"

int main()
{
	Zombie *zHorde;
	int		N;
	
	/* Implement your own tests to ensure your zombieHorde() function works as expected. */
	N = 10;
	zHorde = zombieHorde(N, "zHorde");
	/* Try to call announce() for each one of the zombies. */
	for (int index = 0; index < N; index++)
		zHorde[index].announce();
	/* Don’t forget to delete all the zombies and check for memory leaks. */
	delete []zHorde;
	return (EXIT_SUCCESS);
}
