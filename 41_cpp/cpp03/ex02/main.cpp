#include "FragTrap.hpp"

int	main(void)
{
	FragTrap A("A");
	FragTrap B("B");
	FragTrap C(A);

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
	A.highFivesGuys();
	return (0);
}
