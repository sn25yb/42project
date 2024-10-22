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
	Floor	floor;
	
	ice = src->createMateria("ice");
	me->equip(ice);
	cure = src->createMateria("cure");
	me->equip(cure);
	cure2 = src->createMateria("cure");
	me->equip(cure2);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(0);
	floor.add_floor_invetory(ice);
	me->unequip(1);
	floor.add_floor_invetory(cure);
	me->unequip(2);
	floor.add_floor_invetory(cure2);
	
	delete bob;
	delete me;
	delete src;
	return 0;
}