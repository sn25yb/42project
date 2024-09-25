#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	(void) animal;
	(void) cat;
	(void) dog;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	animal->makeSound();

	delete animal;
	delete dog;
	delete cat;

	const WrongAnimal* wronganimal = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();
	const WrongCat* wrongcat2 = new WrongCat();

	std::cout << wrongcat->getType() << " " << std::endl;
	wronganimal->makeSound();
	wrongcat->makeSound();
	wrongcat2->makeSound();

	delete wronganimal;
	delete wrongcat;
	delete wrongcat2;
	return 0;
}