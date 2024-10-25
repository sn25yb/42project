# include <iostream>

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Floor.hpp"

// void leak()
// {
// 	system("leaks amateria");
// }

int	main()
{
	// atexit(leak);
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* ice;
	AMateria* cure;
	AMateria* cure2;
	AMateria* cure3;
	// AMateria* cure4;
	// AMateria* cure5;
	// AMateria* cure6;
	// AMateria* cure7;
	Floor	floor;
	
	ice = src->createMateria("ice");
	me->equip(ice);
	cure = src->createMateria("cure");
	me->equip(cure);
	cure2 = src->createMateria("cure");
	me->equip(cure2);
	cure3 = src->createMateria("cure");
	me->equip(cure3);
	// cure4 = src->createMateria("cure");
	// me->equip(cure4);
	// cure5 = src->createMateria("cure");
	// me->equip(cure5);
	// cure6 = src->createMateria("cure");
	// me->equip(cure6);
	// cure7 = src->createMateria("cure");
	// me->equip(cure7);

	// printf("%p\n", ice);
	// printf("%p\n", cure);
	// printf("%p\n", cure2);
	// printf("%p\n", cure3);
	// printf("%p\n", cure4);
	// printf("%p\n", cure5);
	// printf("%p\n", cure6);
	// printf("%p\n", cure7);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(0);
	floor.add_floor_invetory(ice);
	me->unequip(1);
	floor.add_floor_invetory(cure);
	me->unequip(2);
	floor.add_floor_invetory(cure2);
	me->unequip(3);
	floor.add_floor_invetory(cure3);
	me->unequip(4);
	
	delete bob;
	delete me;
	delete src;
	return 0;
}