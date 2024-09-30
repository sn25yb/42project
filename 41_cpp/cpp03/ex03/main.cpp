#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap A("A");
	DiamondTrap B("B");
	DiamondTrap A2(A);
	ClapTrap C;
	ScavTrap D;
	FragTrap E;

	// whoAmI	
	A.whoAmI();
	B.whoAmI();
	A2.whoAmI();
	// getstat (before)
	A.getstat();
	B.getstat();
	A2.getstat();
	C.getstat();
	D.getstat();
	E.getstat();
	// attack, takeDamage
	B.beRepaired(100);
	for (int index = 0; index < 100; index++)
	{
		A.attack("B");
		B.takeDamage(2);
	}
	// beRepaired
	A.beRepaired(10);
	B.beRepaired(10);
	// getstat (after)
	A.getstat();
	B.getstat();
	A2.getstat();
	return (0);
}