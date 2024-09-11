#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# define PBMAX 8

class PhoneBook
{
	private:
		Contact contacts[PBMAX];
		int		index;
	public:
		PhoneBook();
		~PhoneBook();
		void	add_phonebook(void);
		void	display_phonebook(void);
		void	search_phonebook(void);
};

#endif
