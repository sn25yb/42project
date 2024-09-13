#include <iostream>

int main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;
	

	std::cout << "❯ Print Memory Address." << std::endl;
	std::cout << "STR Address: " << &brain << std::endl;
	std::cout << "PTR Address: " << stringPTR << std::endl;
	std::cout << "REF Address: " << &stringREF << std::endl;

	std::cout << "❯ Print Value." << std::endl;
	std::cout << "STR Value: " << brain << std::endl;
	std::cout << "PTR Value: " << *stringPTR << std::endl;
	std::cout << "REF Value: " << stringREF << std::endl;

	return (0);
}
