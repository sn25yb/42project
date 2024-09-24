#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# define PAGE 8

class PhoneBook
{
	private:
		std::string	classname;
		Contact		contacts[PAGE];
		int			addindex;
	public:
		/* CONSTRUCTOR */
		PhoneBook();
		/* DESTRUCTOR */
		~PhoneBook();
		/* FUNCTION */
		void		add_phonebook(void);
		void		display_phonebook(void);
		void		search_phonebook(void);
		std::string	get_index(const std::string str);
};

#endif