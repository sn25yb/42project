#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "OCCF.hpp"

# define INUMS 4

class Character : public ICharacter
{
	private:
		std::string					name;
		AMateria					*inventory[INUMS];
	public:
		/* ORTHODOX CANONICAL FORM */
									Character();
									Character(const Character& character);
		Character& 					operator= (const Character& character);
									~Character();
		/* CONSTRUCTOR */
									Character(std::string _name);
		/* FUNCTION */
		virtual std::string const & getName() const;
		virtual void				equip(AMateria* m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter& target);
};

#endif