#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <sstream>

//Contact members
# define FN "FirstName"
# define LN "LastName"
# define NN "NickName"
# define PN "PhoneNumber"
# define DS "DarkestSecret"

//display column
# define SEP "|"
# define FILL ' '
# define LEN 10

//bool
# define FALSE 0
# define TRUE 1

class Contact
{
	private:
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNumber;
		std::string DarkestSecret;
		int			index;
	public:
		Contact();
		~Contact();
		void		add_contact(int index);
		void		display_contact(int attribute_on);
		std::string get_contact(const std::string str, int intopt);
		void		display_column(std::string str);
		void		display_attribute(void);
};

#endif
