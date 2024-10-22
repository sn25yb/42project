#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

# define OCCF0 " constructor called."
# define OCCF1 " copy constructor called."
# define OCCF2 " copy assignment operator called."
# define OCCF3 " destructor called."
# define NOTICE " ❯ "
# define NSPACE "   "

class Brain
{
	private:
		std::string	classname;
		std::string	ideas[100];
	public:
		/* ORTHODOX CANONICAL FORM */
					Brain();
					Brain(const Brain& brain);
		Brain&		operator= (const Brain& brain);
		virtual		~Brain();
};

#endif