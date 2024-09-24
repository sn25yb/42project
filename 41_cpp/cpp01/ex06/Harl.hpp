#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

# define OCCF0 " constructor called."
# define OCCF3 " destructor called."
# define levelsnum 4

class Harl
{
	private:
		std::string	classname;
		void		debug( void );
		void		info( void );
		void		warning( void );
		void		error( void );
	public:
					Harl();
					~Harl();
		void		complain( std::string level );
};



#endif
