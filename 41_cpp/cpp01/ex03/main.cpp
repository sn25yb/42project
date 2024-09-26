#include "HumanA.hpp"
#include "HumanB.hpp"

// void leaks()
// {
// 	system("leaks weapon");
// }

int main()
{
	// atexit(leaks);
	{
		Weapon club = Weapon("crude spiked club");
		// Weapon club2 = Weapon("crude spiked club2");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
		// bob.setWeapon(club2);
		// bob.attack();
	}

	std::cout << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
