#include "Character.hpp"

/* ORTHODOX CANONICAL FORM */
Character::Character()
{
	this->name = "default";
	// std::cout << "[Character]" << this->name << OCCF0 << std::endl;
}

Character::Character(const Character& character)
{
	for (int idx = 0; idx < INUMS; idx++)
		this->inventory[idx] = 0;
	if (this != &character)
	{
		for (int idx = 0; idx < INUMS; idx++)
			if (character.inventory[idx])
				this->inventory[idx] = character.inventory[idx]->clone();
	}
	// std::cout << "[Character]" << this->name << OCCF1 << std::endl;
}

Character& Character::operator= (const Character& character)
{
	if (this != &character)
	{
		for (int idx = 0; idx < INUMS; idx++)
			delete this->inventory[idx];
		for (int idx = 0; idx < INUMS; idx++)
			if (character.inventory[idx])
				this->inventory[idx] = character.inventory[idx]->clone(); //idx 세그폴트 ㅎㅎ 
	}
	// std::cout << "[Character]" << this->name << OCCF2 << std::endl;
	return (*this);
}

Character::~Character()
{
	for (int idx = 0; idx < INUMS; idx++)
		if (inventory[idx])
			delete inventory[idx];
	// std::cout << "[Character]" << this->name << OCCF3 << std::endl;
}

/* CONSTRUCTOR */
Character::Character(std::string _name)
{
	this->name = _name;
	// std::cout << "[Character]" << this->name << OCCF0 << std::endl;
}

/* FUNCTION */
std::string const& Character::getName() const
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	for (int idx = 0; idx < INUMS; idx++)
	{
		if (!this->inventory[idx])
		{	
			this->inventory[idx] = m;
			break ;
		}
		else if (idx + 1 == INUMS)
		{
			delete m;
			std::cout << "You equiped 4 materias already." << std::endl;
			break ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < INUMS && this->inventory[idx])
		this->inventory[idx] = 0;
	// 	std::cout << this->name << " unequip " << this->inventory[idx]->getType() << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (this->inventory[idx])
		this->inventory[idx]->use(target);
}
