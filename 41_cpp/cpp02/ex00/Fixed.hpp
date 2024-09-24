#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					fixed_point;
		static const int	frac_bit = 8;
	public:
		/* ORTHODOX CANONICAL FORM */
		Fixed(void);
		Fixed(const Fixed& fixed);
		Fixed& operator = (const Fixed& fixed);
		~Fixed();
		/* FUNCTION */
		/* [1] get, set */
		int		getRawBits( void ) const;
		void	setRawBits( int const raw ); 
};

#endif
