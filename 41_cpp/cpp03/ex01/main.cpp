#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap A("A");
	ScavTrap B("B");
	ScavTrap C(A);

	// getstat (before)
	A.getstat();
	B.getstat();
	C.getstat();
	// attack, takeDamage
	B.beRepaired(50);
	for (int index = 0; index < 50; index++)
	{
		A.attack("B");
		B.takeDamage(3);
	}
	// beRepaired
	A.beRepaired(10);
	B.beRepaired(10);
	// getstat (after)
	A.getstat();
	B.getstat();
	C.getstat();
	// guardGate
	A.guardGate();
	B.guardGate();
	C.guardGate();
	return (0);
}