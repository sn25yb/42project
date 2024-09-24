#include "Zombie.hpp"

// void leaks()
// {
// 	system("leaks zombiehorde");
// }

int main()
{
	// atexit(leaks);
	Zombie *zHorde;
	int		N;
	
	N = 10;
	zHorde = zombieHorde(N, "zHorde");
	for (int index = 0; index < N; index++)
		zHorde[index].announce();
	delete []zHorde;
	return (EXIT_SUCCESS);
}
