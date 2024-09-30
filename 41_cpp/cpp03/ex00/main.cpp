#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap A("A");
	ClapTrap B("B");
	ClapTrap C(A);

	// getstat (before)
	A.getstat();
	B.getstat();
	C.getstat();
	// attack, takeDamage
	B.beRepaired(10);
	for (int index = 0; index < 10; index++)
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
	C.getstat();
	return (0);
}
