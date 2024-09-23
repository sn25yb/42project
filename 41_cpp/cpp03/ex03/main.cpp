#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap A("A");
	DiamondTrap B("B");
	DiamondTrap C(A);

	A.getstat();
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
	A.whoAmI();
	return (0);
}
