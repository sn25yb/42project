#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();


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

	delete dog;//should not create a leak
	delete cat;

	for (int index = 0; index < 4; index++)
	{
		std::cout << index;
		delete animal[index];
	}
	return (0);
}