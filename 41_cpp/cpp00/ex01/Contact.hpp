#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <limits>

# define OCCF0 " constructor called."
# define OCCF3 " destructor called."
# define NOTICE " ❯ "
# define NSPACE "   "

//Contact members
# define FN "FirstName"
# define LN "LastName"
# define NN "NickName"
# define PN "PhoneNumber"
# define DS "DarkestSecret"

//display column
# define LEN 10
# define MORE '.'
# define FILL ' '
# define SEP "|"

//bool
# define FALSE 0
# define TRUE 1

class Contact
{
	private:
		std::string	classname;
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phonenumber;
		std::string	darkestsecret;
		int			Cindex;
	public:
		/* CONSTRUCTOR */
		Contact();
		/* DESTRUCTOR */
		~Contact();
		/* FUNCTION */
		void		add_contact(int index);
		void		display_contact(int attribute_on);
		std::string	get_contact(const std::string str, int num_opt);
		void		display_column(std::string str);
		void		display_attribute(void);
		int			valid_phonenumber(std::string str);
};

#endif
