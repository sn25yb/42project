#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// void	leaks()
// {
// 	system("leaks animal");
// }

int main()
{
	// atexit(leaks);
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << std::endl;

	delete dog;
	delete cat;
	std::cout << std::endl;

	Animal *animal[4];
	for (int index = 0; index < 2; index++)
	{
		std::cout << index << ' ';
		animal[index] = new Dog();
	}
	std::cout << std::endl;
	for (int index = 2; index < 4; index++)
	{
		std::cout << index << ' ';
		animal[index] = new Cat();
	}
	std::cout << std::endl;

	for (int index = 0; index < 4; index++)
	{
		std::cout << index << ' ';
		delete animal[index];
	}
	std::cout << std::endl;
	return (0);
}