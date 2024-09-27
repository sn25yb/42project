#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap A("A");
	ClapTrap B("B");
	ClapTrap C(A);

	A.attack("B");
	B.takeDamage(5);
	B.beRepaired(10);
	for (int index = 0; index < 10; index++)
	// for (int index = 0; index < 9; index++)
	{
		A.attack("B");
		// B.takeDamage(1);
	}
	B.attack("A");
	A.takeDamage(11);
	A.beRepaired(10);
	return (0);
}
