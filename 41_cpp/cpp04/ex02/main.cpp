#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// void	leaks()
// {
// 	system("leaks brain");
// }

int main()
{
	// atexit(leaks);

	// Animal A;
	// A.makeSound();
	// Animal *a = new Animal();
	// a->makeSound();

	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	delete dog;
	delete cat;

	Animal *animal[4];
	for (int index = 0; index < 2; index++)
	{
		std::cout << index;
		animal[index] = new Dog();
	}
	for (int index = 2; index < 4; index++)
	{
		std::cout << index;
		animal[index] = new Cat();
	}
	for (int index = 0; index < 4; index++)
	{
		std::cout << index;
		delete animal[index];
	}
	return (0);
}