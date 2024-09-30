#include "FragTrap.hpp"

int	main(void)
{
	FragTrap A("A");
	FragTrap B("B");
	FragTrap A2(A);

	// getstat (before)
	A.getstat();
	B.getstat();
	A2.getstat();
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
	// guardGate
	A.highFivesGuys();
	B.highFivesGuys();
	A2.highFivesGuys();
	return (0);
}