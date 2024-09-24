#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie				*zhorde;
	std::stringstream	zindex;
	std::string			zname;

	zhorde = new Zombie[N];
	for (int index = 0; index < N; index++)
	{
		zindex.str(std::string());
		zindex << index;
		zname = name + "_" + zindex.str();
		zhorde[index].setName(zname);
		std::cout << " ❯ Zombie " << zname << " is created." << std::endl;
	}
	return (zhorde);
}
