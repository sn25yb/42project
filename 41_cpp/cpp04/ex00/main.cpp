#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << std::endl;

	std::cout << animal->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << std::endl;
	
	animal->makeSound();
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	std::cout << std::endl;

	delete animal;
	delete dog;
	delete cat;
	std::cout << std::endl;

	const WrongAnimal* wronganimal = new WrongAnimal();
	const WrongAnimal* wrongcat1 = new WrongCat();
	const WrongCat* wrongcat2 = new WrongCat();
	std::cout << std::endl;

	std::cout << wronganimal->getType() << " " << std::endl;
	std::cout << wrongcat1->getType() << " " << std::endl;
	std::cout << wrongcat2->getType() << " " << std::endl;
	std::cout << std::endl;

	wronganimal->makeSound();
	wrongcat1->makeSound();
	wrongcat2->makeSound();
	std::cout << std::endl;

	delete wronganimal;
	delete wrongcat1;
	delete wrongcat2;
	std::cout << std::endl;
	return 0;
}