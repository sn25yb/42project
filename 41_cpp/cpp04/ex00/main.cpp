#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	//construct
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const Cat* cat2 = new Cat();
	std::cout << std::endl;
	
	//gettype
	std::cout << animal->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << cat2->getType() << " " << std::endl;
	std::cout << std::endl;
	
	//makesound
	animal->makeSound();
	dog->makeSound();
	cat->makeSound();
	cat2->makeSound();
	std::cout << std::endl;

	//delete
	delete animal;
	delete dog;
	delete cat;
	delete cat2;
	std::cout << std::endl;

	//construct
	const WrongAnimal* wronganimal = new WrongAnimal();
	const WrongAnimal* wrongcat1 = new WrongCat();
	const WrongCat* wrongcat2 = new WrongCat();
	std::cout << std::endl;

	//gettype
	std::cout << wronganimal->getType() << " " << std::endl;
	std::cout << wrongcat1->getType() << " " << std::endl;
	std::cout << wrongcat2->getType() << " " << std::endl;
	std::cout << std::endl;

	//makesound
	wronganimal->makeSound();
	wrongcat1->makeSound();
	wrongcat2->makeSound();
	std::cout << std::endl;

	//delete
	delete wronganimal;
	delete wrongcat1;
	delete wrongcat2;
	std::cout << std::endl;
	return 0;
}