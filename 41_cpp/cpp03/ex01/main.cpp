#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap A("A");
	ScavTrap B("B");
	ScavTrap C(A);

	A.attack("B");
	B.takeDamage(5);
	B.beRepaired(10);
	for (int index = 0; index < 50; index++)
	{
		A.attack("B");
		// B.takeDamage(1);
	}
	B.attack("A");
	A.takeDamage(101);
	A.beRepaired(10);
	A.guardGate();
	return (0);
}
